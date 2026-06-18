`include "define.v"

module csr(
  input clk,
  input rst,

  input csr_write_enable,      //csr写使能
  input csr_write_sel,         //csr写入数据选择, 0表示写入寄存器值, 1表示写入按位与
  input [11:0] csr_addr,       //csr地址
  input [31:0] csr_write_data, //csr写数据

  //有关ecall和mret
  input ecall_valid,
  input [31:0] exec_PC,
  output [31:0] mtvec_value,
  output [31:0] mepc_value,

  output reg [31:0] csr_read_data //csr读数据
);

//定义mcycle和mcycleh寄存器
reg [31:0] mcycle;
reg [31:0] mcycleh;
//定义mvendroid
reg [31:0] mvendorid;
reg [31:0] marchid;
//定义mepc等
reg [31:0] mepc;
reg [31:0] mtvec;
reg [31:0] mcause;
reg [31:0] mstatus;

always @(posedge clk) begin
  if (rst) begin
    mcycle <= 32'b0;
    mcycleh <= 32'b0;
    mvendorid <= 32'h79737978;
    marchid <= 32'd26060176;
    mepc <= 32'b0;
    mtvec <= 32'b0;
    mcause <= 32'b0;
    mstatus <= 32'h1800;
  end else begin
    mcycle <= mcycle + 1;
    if (mcycle == 32'hffffffff) begin
      mcycleh <= mcycleh + 1;
    end
  end
end

always @(posedge clk) begin
  //ecall需要在一个周期内写两个，所以为ecall单独开普一个写口
  if (ecall_valid) begin
    mepc <= exec_PC; //将发生ecall的指令地址写入mepc
    mcause <= 32'd11; //设置mcause为环境调用
  end
  else if(csr_write_enable) begin
    case (csr_addr)
      12'hB00: mcycle <= csr_write_sel ? (mcycle | csr_write_data) : csr_write_data ; //写mcycle
      12'hB80: mcycleh <= csr_write_sel ? (mcycle | csr_write_data) : csr_write_data ; //写mcycleh
      12'h341: mepc <= csr_write_sel ? (mepc | csr_write_data) : csr_write_data ; //写mepc
      12'h305: mtvec <= csr_write_sel ? (mtvec | csr_write_data) : csr_write_data ; //写mtvec
      12'h342: mcause <= csr_write_sel ? (mcause | csr_write_data) : csr_write_data ; //写mcause
      12'h300: mstatus <= csr_write_sel ? (mstatus | csr_write_data) : csr_write_data ; //写mstatus
      default: ; //其他CSR地址暂不处理
    endcase
  end
end


assign mtvec_value = mtvec;
assign mepc_value = mepc;

always @(*) begin
  case (csr_addr)
    12'hB00: csr_read_data = mcycle; //读mcycle
    12'hB80: csr_read_data = mcycleh; //读mcycleh
    12'hF11: csr_read_data = mvendorid; //读mvendorid
    12'hF12: csr_read_data = marchid; //读marchid
    12'h341: csr_read_data = mepc; //读mepc
    12'h305: csr_read_data = mtvec; //读mtvec
    12'h342: csr_read_data = mcause; //读mcause
    12'h300: csr_read_data = mstatus; //读mstatus
    default: csr_read_data = 32'b0; //其他CSR地址返回0
  endcase
end

endmodule