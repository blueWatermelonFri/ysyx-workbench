import "DPI-C" function int npcmem_read(input int raddr);

module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk
);
  wire vaild; // mem read
  reg [31:0] mem_rdata;
  wire [6:0] opcode;

  // adder input output
  wire [31:0] addr;
  wire [31:0] add_input1;
  wire [31:0] add_input2;

  always @(*) begin
    $display("inst = %h\n", rst);
    
  end

endmodule