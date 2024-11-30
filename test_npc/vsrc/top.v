import "DPI-C" function void ebreak();
import "DPI-C" function int npcmem_read(input int raddr);
import "DPI-C" function void npcmem_write(input int waddr, input int wdata, input byte wmask);

module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC


);
  wire [31:0] SPC;
  wire [31:0] DPC;

  wire wen; // reg write
  wire read_mem; // mem read
  wire write_mem; // mem write
  wire [31:0] wdata; // reg write
  wire [31:0] rs1data; // reg read rs1
  wire [31:0] rs2data; // reg read rs2


  // for mem read extract and sext
  wire [31:0] mem_read_res;
  wire [31:0] mem_lh_sext;
  wire [31:0] mem_lb_sext;
  wire [31:0] mem_no_sext;
  wire [31:0] mem_extract;

  // for mem write extract and sext
  wire [7:0] wmask;
  wire [31:0] wdata;


  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wen(1),
  .wdata(1),
  .waddr(1),
  .rs1addr(1),
  .rs2addr(1),
  .rs1data(rs1data),
  .rs2data(rs2data)
  );

  wire [31:0] wire_var;
  reg [31:0] reg_var;
  assign wire_var = reg_var;

  always @(inst) begin
      reg_var = npcmem_read(inst);
      $display("reg var = %h\n", reg_var);
      $display("wire var = %h\n", wire_var);

  end

  // ebreak


endmodule

// add
// sub
// xor
// or
// and
// sll
// srl
// sra
// slt
// sltu
// addi
// xori
// ori
// andi   1
// slli
// srli
// srai
// slti
// sltiu
// lb
// lh
// lw
// lbu
// lhu
// sb
// sh
// sw
// beq
// bne
// blt
// bge
// bltu
// bgeu
// jal    1
// jalr   1
// lui
// auipc  1