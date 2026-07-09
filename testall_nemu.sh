#!/bin/bash

# 如果发生错误，立即退出脚本
set -e
# 开启 pipefail：如果管道流中后续命令（如 awk）报错返回 1，则整个管道流视为报错 1，从而触发 set -e 退出
set -o pipefail

# 定位仓库根目录；NEMU_HOME 未在 ~/.bashrc 导出时这里兜底设置
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export NEMU_HOME="${NEMU_HOME:-$SCRIPT_DIR/nemu}"

# —— 自动完成 clone 后的首次配置，替代手动 `cd nemu && make menuconfig` ——
# 原理：nemu/.config 与 include/generated/autoconf.h 已随仓库提交，clone 后即存在；
# 但 nemu/include/config/auto.conf 被 .gitignore 忽略，clone 后缺失。而 NEMU 的 Makefile
# 正是通过 -include auto.conf 读取 CONFIG_ISA / CONFIG_DEVICE / CC 等构建变量，缺失时
# GUEST_ISA 等全为空、构建必坏。`make menuconfig` 能修复，本质只是它结尾跑了一次
# `conf --syncconfig`，按 .config 重新生成 auto.conf 等派生文件。这里直接非交互地编译
# conf 工具并执行 syncconfig，幂等：仅当 auto.conf 缺失或比 .config 旧时才跑。
AUTO_CONF="$NEMU_HOME/include/config/auto.conf"
if [ ! -f "$AUTO_CONF" ] || [ "$NEMU_HOME/.config" -nt "$AUTO_CONF" ]; then
  echo "==> Initializing NEMU config (regenerating auto.conf from .config)..."
  ( cd "$NEMU_HOME" && make -s -C tools/kconfig NAME=conf && ./tools/kconfig/build/conf -s --syncconfig Kconfig )
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
