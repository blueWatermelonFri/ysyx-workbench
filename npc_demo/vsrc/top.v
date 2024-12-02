module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk

);

  reg [31:0] PC; //


  always @(posedge clk) begin
    if (rst) PC <= 32'h8000_0000;
    else  PC <= PC + 32'h4;
  end


endmodule