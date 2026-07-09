#!/bin/bash

# 如果发生错误，立即退出脚本
set -e
# 开启 pipefail：如果管道流中后续命令（如 awk）报错返回 1，则整个管道流视为报错 1，从而触发 set -e 退出
set -o pipefail

# 定位仓库根目录。NEMU_HOME 强制指向【本仓库自带】的 nemu，而不是沿用 ~/.bashrc 里
# 导出的那个 —— 否则在新 clone 出来的目录里跑本脚本，会去 build 别处（如 ~/Desktop）
# 的旧 nemu，出现 "fixdep: not found" 或配置对不上等诡异错误。本脚本的语义就是
# "测试本仓库的 nemu"，所以无视外部 NEMU_HOME。（该 export 只影响本脚本子进程，
# 不改你交互式 shell 的 NEMU_HOME。）
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export NEMU_HOME="$SCRIPT_DIR/nemu"

# —— 自动完成 clone 后的首次配置，彻底替代手动 `cd nemu && make menuconfig` ——
# 全新 clone 后缺两样东西（都被 .gitignore 忽略，不随仓库提交）：
#   1) nemu/include/config/auto.conf —— NEMU 的 Makefile 通过 -include 它读取
#      CONFIG_ISA / CONFIG_DEVICE / CC 等构建变量，缺失则 GUEST_ISA 等全空、构建必坏。
#   2) nemu/tools/{kconfig,fixdep}/build/ 下的宿主工具 conf 与 fixdep —— NEMU 编译每个
#      .o 都会调用 fixdep，但普通 `make` 不会自动编它（build.mk 的 %.o 规则没把 fixdep
#      列为先决条件），只有 menuconfig / *defconfig 目标会把它编出来。所以 clone 后
#      第一次 `make` 必报 "fixdep: not found"。
# 手动 `make menuconfig` 之所以能"修好"，是因为它一次性把 conf + fixdep 都编了，结尾还
# 跑了一次 `conf --syncconfig` 按 .config 重新生成 auto.conf（产出的 auto.conf 与
# menuconfig 逐字节一致）。这里等价地、非交互地做完这三件事：先确保 conf / fixdep
# 存在（缺了才编），再仅当 auto.conf 缺失或比 .config 旧时跑一次 syncconfig（幂等）。
( cd "$NEMU_HOME" \
  && { [ -x tools/kconfig/build/conf ]  || make -s -C tools/kconfig NAME=conf; } \
  && { [ -x tools/fixdep/build/fixdep ] || make -s -C tools/fixdep; } )
AUTO_CONF="$NEMU_HOME/include/config/auto.conf"
if [ ! -f "$AUTO_CONF" ] || [ "$NEMU_HOME/.config" -nt "$AUTO_CONF" ]; then
  echo "==> Initializing NEMU config (regenerating auto.conf from .config)..."
  ( cd "$NEMU_HOME" && ./tools/kconfig/build/conf -s --syncconfig Kconfig )
fi

cd "$SCRIPT_DIR/am-kernels/tests/cpu-tests"

# 遍历 tests 目录下的所有 .c 文件
for file in tests/*.c; do
  # 提取不包含路径和后缀的文件名 (例如: 讲 tests/add.c 提取为 add)
  name=$(basename "$file" .c)

  # 跳过hello-str和string
  # if [[ "$name" == "hello-str" || "$name" == "string" ]]; then
  #   # echo "=================================================="
  #   # echo "Skipping test: $name (not supported in NEMU)"
  #   # echo "=================================================="
  #   continue
  # fi
  
  echo "=================================================="
  echo "Running test: $name"
  echo "=================================================="
  
  # 自动向 NEMU 喂入 c 和 q。
  # 直接将输出通过管道交给 awk 处理，awk 会原样逐行打印终端输出 {print}。
  # 一旦在此期间检测到 "is not implemented" 或者 Makefile 自带的 FAIL 报错，
  # awk 会悄悄记下标记 err=1，并在结束流时返回退出了状态码 1。
  # 因为我们加了 set -o pipefail 和 set -e，一旦状态为 1，整个脚本都会干净利落地中止。
  echo -e "q" | make ARCH=riscv32-nemu ALL="$name" run | awk '{print} /is not implemented/ || /\*\*\*FAIL\*\*\*/ {err=1} END{exit err}'

  # 由于配置了 set -e 和 pipefail，只有当上一条测试完美通过时，脚本才会继续执行到这里。
  # 此时自动清理该测试及其相关的由 AM 框架生成的产物 (通常带有前缀 $name-)。
  # 注意：如果测试失败，脚本已经直接中止退出，保留着报错现场的中间文件供你调试！
  rm -f "build/${name}-"* "Makefile.${name}" 

done

echo "=================================================="
echo "All tests finished successfully!"
echo "=================================================="
