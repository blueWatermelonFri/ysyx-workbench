
module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk
);

  always @(*) begin
    $display("inst = %h\n", rst);
  end

endmodule