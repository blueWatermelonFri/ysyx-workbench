module ysyx_24100005_top(
  input rst,
  input clk,
  input sig

);

  reg PC; //

  always @(posedge clk) begin
    if (rst) PC <= 0;
    else  PC <= sig;
  end


endmodule