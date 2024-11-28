
module ysyx_24100005_top(
  input rst
);

  always @(rst) begin
    $display("rst = %h\n", rst);
  end

endmodule