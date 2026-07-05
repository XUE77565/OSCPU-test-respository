`include "define.v"

module lsu_mem(
  input   clk,
  input   rst,

//请求通道
  input          MemRead,
  input          MemWrite,
  input   [31:0] Address,
  input   [31:0] Write_data,
  input   [3:0]  Write_strb,
  output         Mem_Req_Ready,

//响应通道
  output  [31:0] Read_data,
  output         Read_data_Valid,//相当于respValid，写通道也用这个表示完成
  input          Read_data_Ready
);

  // ===== 随机延迟测试支持 =====
  // 状态机: IDLE 收请求 → WAIT_D 倒数延迟 → RESP 返回响应
  // delay_cnt 来源: 固定 8'd5 (讲义第1步) 或 lfsr[3:0] 随机 (讲义第2步)
  localparam IDLE   = 2'd0,
             WAIT_D = 2'd1,
             RESP   = 2'd2;
  reg [1:0]  state;
  reg [31:0] Read_data_reg;
  reg [7:0]  delay_cnt;

  wire mem_request  = (MemRead || MemWrite) && Mem_Req_Ready;//请求通道握手成功
  wire mem_response = Read_data_Valid && Read_data_Ready;//响应通道握手成功

  // LFSR 产生伪随机数 (种子与 ifu_mem 不同, 避免两边延迟序列同步)
  reg [15:0] lfsr;
  always @(posedge clk) begin
    if (rst) lfsr <= 16'h5678;
    else     lfsr <= {lfsr[14:0], lfsr[15]^lfsr[13]^lfsr[12]};
  end

  // 只在空闲时才能接收新请求 (一次处理一个请求)
  assign Mem_Req_Ready = (state == IDLE);

  always @(posedge clk) begin
    if (rst) begin
      state         <= IDLE;
      Read_data_reg <= 32'b0;
      delay_cnt     <= 8'b0;
    end else begin
      case (state)
        IDLE: begin
          if (mem_request) begin//握手成功, 接受请求
            if (MemRead)       Read_data_reg <= pmem_read(Address);          // 读: 存数据
            else if (MemWrite) pmem_write(Address, Write_data, Write_strb);  // 写: 立即写入
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
          // 响应有效(读=数据有效, 写=完成), 等待 master 取走
          if (mem_response) state <= IDLE;
        end
        default: state <= IDLE;
      endcase
    end
  end

  assign Read_data       = Read_data_reg;
  assign Read_data_Valid = (state == RESP); // 延迟后才有效(=respValid)

endmodule
