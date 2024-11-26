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
  wire [31:0] rdata; // reg read

  reg [31:0] mem_rdata;


  wire [6:0] opcode;
  wire [2:0] funct3;
  wire [4:0] rs1;
  wire [11:0] imm;
  wire [4:0] rd;

  wire [31:0] immI;
  wire [31:0] immJ;
  wire [31:0] immU;
  wire [31:0] shiftimmU;



  // adder input output
  wire [31:0] add_output;
  wire [31:0] add_input1;
  wire [31:0] add_input2;


  // 初始化寄存器堆
  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wdata(wdata),
  .waddr(rd),
  .raddr(rs1),
  .wen(wen),
  .rdata(rdata)
  );

  // PC更新
  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk), 
                                              .rst(rst), 
                                              .din(DPC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  // static next pc
  assign SPC = PC + 32'h0000_0004;

  // decode 
  assign opcode = inst[6:0];
  assign rd = inst[11:7];

  // I type instruction
  assign funct3 = inst[14:12];
  assign rs1 = inst[19:15];
  // imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Iimm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:20]},
                                                                1'b1, {20'hfffff, inst[31:20]}
                                                              }),
                                                          .out(immI));
  // U type instruction
  // imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Uimm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {12'h000, inst[31:12]},
                                                                1'b1, {12'hfff, inst[31:12]}
                                                              }),
                                                          .out(immU));
  // U type imm shift
  assign shiftimmU = {immU[19:0], 12'h000};

  // j type instruction

  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Jimm_SEXT (.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {11'h000, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0},
                                                                1'b1, {11'hfff, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}
                                                              }),
                                                          .out(immJ));


  // mux for adder input2(imm)     NR_KEY , KEY_LEN , DATA_LEN 
  ysyx_24100005_MuxKeyWithDefault #(7, 7, 32) Mux_input2 (.out(add_input2), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, immI,
                                                                7'b001_0111, shiftimmU, // aipuc
                                                                7'b011_0111, shiftimmU, // lui
                                                                7'b110_1111, immJ,      // jal
                                                                7'b110_0111, immI,       // jalr
                                                                7'b000_0011, immI, // load
                                                                7'b010_0011, immI // store                                                                
                                                                }));

  // mux for adder input1 (reg/pc)
  ysyx_24100005_MuxKeyWithDefault #(6, 7, 32) Mux_input1 (.out(add_input1), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, rdata, // partial I type
                                                                7'b001_0111, PC, // lui
                                                                7'b110_1111, PC, // jal
                                                                7'b110_0111, rdata,  // jalr
                                                                7'b000_0011, rdata, // load
                                                                7'b010_0011, rdata // store
                                                                }));

  assign add_output = add_input1 + add_input2;

  // write back 
  // mux for weather write back 
  ysyx_24100005_MuxKeyWithDefault #(6, 7, 1) Mux_iswrite (.out(wen), 
                                                        .key(opcode), 
                                                        .default_out(1'b1), 
                                                        .lut({
                                                              7'b110_0011, 1'b0, // B type
                                                              7'b010_0011, 1'b0,  // S type
                                                              7'b110_1111, 1'b1,  // jal
                                                              7'b110_0111, 1'b1,   // jalr
                                                              7'b000_0011, 1'b1, // load
                                                              7'b010_0011, 1'b1 // store                                                              
                                                              }));

  // mux for update PC
  ysyx_24100005_MuxKeyWithDefault #(8, 7, 32) Mux_PC (.out(DPC), 
                                                      .key(opcode), 
                                                      .default_out(SPC), 
                                                      .lut({
                                                            7'b011_0011, SPC,         // R type
                                                            7'b001_0011, SPC,         // partial I type
                                                            7'b000_0011, SPC,         // partial I type
                                                            7'b010_0011, SPC,         // S type
                                                            7'b011_0111, SPC,         // U type
                                                            7'b110_0011, add_output, // B type
                                                            7'b110_1111, add_output,  // jal
                                                            7'b110_0111, add_output  // jalr                                                            
                                                            }));

  // mux for write back in [add_output , SNPC, mem_read]
  ysyx_24100005_MuxKeyWithDefault #(3, 7, 32) Mux_writedata (.out(wdata), 
                                                              .key(opcode), 
                                                              .default_out(add_output), 
                                                              .lut({
                                                                    7'b110_1111, SPC,  // jal
                                                                    7'b110_0111, SPC,  // jalr   
                                                                    7'b000_0011, mem_read,  // load
                                                                    }));



  // mux for weather load
  ysyx_24100005_MuxKeyWithDefault #(2, 7, 1) Mux_writedata (.out(read_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b1,  // load
                                                                    7'b010_0011,  1'b1  // store                                                           
                                                                    }));

  // mux for weather store
  ysyx_24100005_MuxKeyWithDefault #(2, 7, 1) Mux_writedata (.out(write_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b0,  // load
                                                                    7'b010_0011,  1'b1  // store                                                           
                                                                    }));

  // mem_read extension 如何判断指令集是不是四字节对齐？
  ysyx_24100005_MuxKeyWithDefault #(5, 1, 32) Iimm_SEXT(.key({funct3, add_output[1:0]}),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                5'b000_00, {24'h000000, mem_rdata[7:0]},
                                                                5'b000_01, {16'h0000, mem_rdata[15:8], 8'h00},
                                                                5'b000_10, {8'h00, mem_rdata[23:16], 16'h0000},
                                                                5'b000_11, {mem_rdata[31:24], 24'h000000},

                                                                5'b000_00, {16'h000000, mem_rdata[15:0]},
                                                                5'b000_01, {8'h0000, mem_rdata[23:8], 8'h00},
                                                                5'b000_10, {mem_rdata[31:16], 16'h0000},



                                                                1'b0, {20'h00000, inst[31:20]},
                                                                1'b1, {20'hfffff, inst[31:20]}
                                                              }),
                                                          .out(immI));

  // memory access
  always @(*) begin
    if (read_mem) begin // 有读写请求时 // 可以进一步优化吗，因为代码的逻辑是要写的话就必须读
      mem_rdata = npcmem_read(add_output);
      if (write_mem) begin // 有写请求时
        npcmem_write(add_output, wdata, wmask);
      end
    end
    else begin
      mem_rdata = 0;
    end
  end

  // ebreak
  always @(*) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

  // always @(posedge clk) begin
  //   $display("inst=%h, ", inst);
  //   $display("Opcode=%h, ", opcode);
  //   $display("PC=%h, ", PC);
  //   $display("add1=%h, ", add_input1);
  //   $display("add2=%h, ", add_input2);
  // end

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