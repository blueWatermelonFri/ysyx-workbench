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


  always @(posedge clk) begin
    if (rst) PC <= 32'h8000_0000;
    else  PC <= PC + 32'h4;
  end


  // static next pc
  assign SPC = PC + 32'h0000_0004;


endmodule