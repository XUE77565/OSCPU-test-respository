`include "define.v"

module ifu_mem(
  input   clk,
  input   rst,

//AR
  input   [31:0] PC,
  input          Inst_Req_Valid,
  output         Inst_Req_Ready,

//R
  output  [31:0] Instruction,
  output         Inst_Valid,
  input          Inst_Ready
);

  // ===== 随机延迟测试支持 =====
  // 用状态机替换原来的 busy 单标志: IDLE 收请求 → WAIT_D 倒数延迟 → RESP 返回数据
  // delay_cnt 的来源决定延迟模式:
  //   固定延迟: delay_cnt <= 8'd5;   (讲义第1步, 依次试 5/10/20)
  //   LFSR随机: delay_cnt <= lfsr[3:0];  (讲义第2步, 0~15 拍)
  localparam IDLE   = 2'd0,
             WAIT_D = 2'd1,
             RESP   = 2'd2;
  reg [1:0]  state;
  reg [31:0] ifu_rdata;
  reg [7:0]  delay_cnt;

  wire ar_done = Inst_Req_Valid && Inst_Req_Ready;//AR握手完成
  wire r_done  = Inst_Valid && Inst_Ready;        //R握手完成

  // LFSR 产生伪随机数 (固定种子 → 可复现)
  reg [15:0] lfsr;
  always @(posedge clk) begin
    if (rst) lfsr <= 16'h1234;
    else     lfsr <= {lfsr[14:0], lfsr[15]^lfsr[13]^lfsr[12]};
  end

  // 只在空闲时才能接收新请求 (一次处理一个请求)
  assign Inst_Req_Ready = (state == IDLE);

  always @(posedge clk) begin
    if (rst) begin
      state     <= IDLE;
      ifu_rdata <= 32'b0;
      delay_cnt <= 8'b0;
    end else begin
      case (state)
        IDLE: begin
          if (ar_done) begin
            //地址握手完成, 立即读出数据(存好), 但延迟若干周期才返回
            ifu_rdata <= pmem_read(PC);
            delay_cnt <= lfsr[3:0];   // ← 随机延迟 0~15; 固定延迟改这里, 如 8'd5
            state     <= WAIT_D;
          end
        end
        WAIT_D: begin
          // 倒数延迟, 数完才进入响应状态
          if (delay_cnt == 8'b0) state <= RESP;
          else                   delay_cnt <= delay_cnt - 8'b1;
        end
        RESP: begin
          // 数据有效, 等待 master 取走
          if (r_done) state <= IDLE;
        end
        default: state <= IDLE;
      endcase
    end
  end

  assign Instruction = ifu_rdata;
  assign Inst_Valid  = (state == RESP); // 延迟后才有效

endmodule
