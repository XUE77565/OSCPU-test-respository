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
//定义mvendroid
reg [31:0] mvendorid;
reg [31:0] marchid;

always @(posedge clk) begin
  if (rst) begin
    mcycle <= 32'b0;
    mcycleh <= 32'b0;
    mvendorid <= 32'h79737978;
    marchid <= 32'd26060176;
  end else begin
    mcycle <= mcycle + 1;
    if (mcycle == 32'hffffffff) begin
      mcycleh <= mcycleh + 1;
    end
  end
end

always @(posedge clk) begin
  if(csr_write_enable) begin
    case (csr_addr)
      12'hB00: mcycle <= csr_write_sel ? (mcycle | csr_write_data) : csr_write_data ; //写mcycle
      12'hB80: mcycleh <= csr_write_sel ? (mcycle | csr_write_data) : csr_write_data ; //写mcycleh
      default: ; //其他CSR地址暂不处理
    endcase
  end
end

always @(*) begin
  case (csr_addr)
    12'hB00: csr_read_data = mcycle; //读mcycle
    12'hB80: csr_read_data = mcycleh; //读mcycleh
    12'hF11: csr_read_data = mvendorid; //读mvendorid
    12'hF12: csr_read_data = marchid; //读marchid
    default: csr_read_data = 32'b0; //其他CSR地址返回0
  endcase
end

endmodule