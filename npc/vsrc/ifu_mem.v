`include "define.v"

//import "DPI-C" function int pmem_read(int raddr);

module ifu_mem(
  input   clk,
  input   rst,

//AR
  input   [31:0] PC,
  input          Inst_Req_Valid,
  output         Inst_Req_Ready,

//R
  input  [31:0]  Instruction,
  output         Inst_Valid,
  input          Inst_Ready
);

  reg [31:0] ifu_rdata;
  reg        ifu_busy;

  wire ar_done = Inst_Req_Valid && Inst_Req_Ready;//AR握手完成
  wire r_done  = Inst_Valid && Inst_Ready;        //R握手完成

  //每次只处理一个指令
  assign Inst_Req_Ready = !ifu_busy;

  always @(posedge clk) begin
    if (rst) begin
      ifu_busy <= 0;
      ifu_rdata <= 0;
    end 
    else begin
      if (ar_done) begin
        //地址握手完成，发出内存读请求
        ifu_rdata <= pmem_read(PC); //从内存读取指令数据
        ifu_busy <= 1; 
      end 
      else if (r_done) begin
        ifu_busy <= 0; //收到R响应后退出忙碌状态，准备处理下一条指令
      end 
      else begin
        ifu_busy <= ifu_busy; //保持当前忙碌状态不变
        ifu_rdata <= ifu_rdata; //保持当前数据不变
      end
    end
  end

  assign Instruction = ifu_rdata;
  assign Inst_Valid = ifu_busy; //当正在处理指令时，输出有效信号

endmodule