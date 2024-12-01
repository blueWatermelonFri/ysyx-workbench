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
  reg [31:0] mem_rdata;
  wire [31:0] mem_read_res;
  wire [31:0] mem_lh_sext;
  wire [31:0] mem_lb_sext;
  wire [31:0] mem_no_sext;
  wire [31:0] mem_extract;

  // for mem write extract and sext
  wire [7:0] wmask;
  wire [31:0] wdata;

  wire [6:0] opcode;
  wire [2:0] funct3;
  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [11:0] imm;
  wire [4:0] rd;

  wire [31:0] immI;
  wire [31:0] immJ;
  wire [31:0] immU;
  wire [31:0] immS;
  wire [31:0] shiftimmU;

  // adder input output
  wire [31:0] add_output;
  wire [31:0] add_input1;
  wire [31:0] add_input2;

  // 初始化寄存器堆
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

  // PC更新
  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk),
                                              .rst(rst), 
                                              .din(DPC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  // static next pc
  assign SPC = PC + 32'h0000_0004;

  // R | I | S | B type
  assign rs1 = inst[19:15];

  // R | S | B type
  assign rs2 = inst[24:20];

  // decode 
  assign opcode = inst[6:0];
  assign rd = inst[11:7];

  // I type instruction
  assign funct3 = inst[14:12];
  // imm extension

  // U type instruction
  // imm extension

  // U type imm shift





  assign add_output = add_input1 + add_input2;



  // mux for update PC
  ysyx_24100005_MuxKeyWithDefault #(8, 7, 32) Mux_PC (.out(DPC), 
                                                      .key(opcode), 
                                                      .default_out(SPC), 
                                                      .lut({
                                                            7'b011_0011, SPC,         // R type
                                                            7'b001_0011, SPC,         // partial I type
                                                            7'b000_0011, SPC,         // load
                                                            7'b010_0011, SPC,         // store
                                                            7'b011_0111, SPC,         // U type
                                                            7'b110_0011, add_output, // B type
                                                            7'b110_1111, add_output,  // jal
                                                            7'b110_0111, add_output  // jalr                                                            
                                                            }));





  // ebreak
  always @(*) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

endmodule