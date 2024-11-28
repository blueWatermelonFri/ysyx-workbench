module ysyx_24100005_top(
);
  wire rst;
  assign rst = 0;
  always @(*) begin
    $display("rst = %h\n", rst);
  end

endmodule