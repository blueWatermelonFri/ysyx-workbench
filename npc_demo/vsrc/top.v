module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] SPC;
  wire [31:0] DPC;
  wire [31:0] rs1data; // reg read rs1
  wire [31:0] rs2data; // reg read rs2
  wire [6:0] opcode;

  // 初始化寄存器堆

  // 初始化寄存器堆
  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wen(1),
  .wdata(1),
  .waddr(1),
  .rs1addr(1),
  .rs2addr(1),
  .rs1data(rs1data),
  .rs2data(rs2data)
  );

  always @(posedge clk) begin
    if (rst) PC <= 32'h8000_0000;
    else  PC <= PC + 32'h4;
  end


  // static next pc
  assign SPC = PC + 32'h0000_0004;


endmodule