module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] Next_PC;

  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk), 
                                              .rst(rst), 
                                              .din(Next_PC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  

  assign Next_PC = PC + 32'h0000_0004;


  always @(posedge clk) begin
    $display("inst=%h, ", inst);
    $display("PC=%h, ", PC);
    $display("Next_PC=%h, ", Next_PC);


  end

endmodule