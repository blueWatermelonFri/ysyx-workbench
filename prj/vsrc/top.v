
module ysyx_24100005_top(
  input clk

);
import "DPI-C" function int add (input int a, input int b);

initial begin
   $display("%x + %x = %x", 1, 2, add(1,2));
end


endmodule
