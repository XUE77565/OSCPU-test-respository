`include "define.v"

module csr(
  input clk,
  input rst,

  input csr_write_enable,      //csr写使能
  input csr_write_sel,         //csr写入数据选择, 0表示写入寄存器值, 1表示写入按位与
  input [11:0] csr_addr,       //csr地址
  input [31:0] csr_write_data, //csr写数据

  output reg [31:0] csr_read_data //csr读数据
);

//定义mcycle和mcycleh寄存器
reg [31:0] mcycle;
reg [31:0] mcycleh;

always @(posedge clk) begin
  if (rst) begin
    mcycle <= 32'b0;
    mcycleh <= 32'b0;
  end else begin
    mcycle <= mcycle + 1;
    if (mcycle == 32'hffffffff) begin
      mcycleh <= mcycleh + 1;
    end
  end
end

if(csr_write_enable) begin
  case (csr_addr)
    12'hB00: mcycle <= csr_write_data; //写mcycle
    12'hB80: mcycleh <= csr_write_data; //写mcycleh
    default: ; //其他CSR地址暂不处理
  endcase
end

endmodule