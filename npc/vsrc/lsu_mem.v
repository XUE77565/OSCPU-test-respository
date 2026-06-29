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


  reg [31:0] Read_data_reg;
  reg        lsu_mem_busy;

  wire mem_request = (MemRead || MemWrite) && Mem_Req_Ready;//请求通道握手成功
  wire mem_response = Read_data_Valid && Read_data_Ready;//响应通道握手成功

  assign Mem_Req_Ready = !lsu_mem_busy;//一次处理一个请求

  always @(posedge clk) begin
    if (rst) begin
      Read_data_reg <= 32'b0;
      lsu_mem_busy <= 1'b0;
    end 
    else if (mem_request) begin//握手成功，接受请求
      if(MemRead) begin//读
        Read_data_reg <= pmem_read(Address);
      end
      else if(MemWrite) begin//写
        pmem_write(Address, Write_data, Write_strb);
      end
      lsu_mem_busy <= 1'b1;//拉高busy，表示正在处理一个请求
    end 
    else if (mem_response) begin//响应被取走，可以处理下一个请求
      lsu_mem_busy <= 1'b0;
    end 
    else begin
      lsu_mem_busy <= lsu_mem_busy;
      Read_data_reg <= Read_data_reg;
    end
  end

  assign Read_data = Read_data_reg;
  assign Read_data_Valid = lsu_mem_busy; // busy 拉高时数据有效(=respValid); 读=数据有效, 写=请求已被接受/完成
endmodule