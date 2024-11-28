import "DPI-C" function int npcmem_read(input int raddr);

module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire vaild; // mem read

  // for mem read extract and sext
  reg [31:0] mem_rdata;

  wire [6:0] opcode;

  // adder input output
  wire [31:0] addr;
  wire [31:0] add_input1;
  wire [31:0] add_input2;

  // assign inst = 32'h0;
  assign add_input1 = 32'h0;
  assign add_input2 = 32'h0;
  assign addr = add_input1 + add_input2;
  assign opcode = inst[6:0];

  // 判断指令是否有读写需求
  ysyx_24100005_MuxKeyWithDefault #(1, 1, 1) Mux_read_mem (.out(vaild), 
                                                              .key(0), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    1'b0,  1'b1  // load
                                                                    }));
  // assign vaild = 1;
  // assign addr = 0;

  always @(*) begin
    $display("vaild = %h\n", vaild);
    if (vaild) begin // 有读写请求时 
      mem_rdata = npcmem_read(0);
    end
    else begin
      mem_rdata = 0;
    end
  end

endmodule

