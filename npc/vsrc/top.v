import "DPI-C" function void ebreak();
import "DPI-C" function int npcmem_read(input int raddr);
import "DPI-C" function void npcmem_write(input int waddr, input int wdata, input byte wmask);

module ysyx_24100005_top(
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] SPC;
  wire [31:0] DPC;
  reg [31:0] inst;

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
  wire [6:0] funct7;
  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [11:0] imm;
  wire [4:0] rd;

  wire [31:0] immI;
  wire [31:0] immJ;
  wire [31:0] immU;
  wire [31:0] immS;
  wire [31:0] immB;
  wire [31:0] shiftimmU;

  // adder input output
  wire [31:0] add_output;
  wire [31:0] add_input1;
  wire [31:0] add_input2;

  // 初始化寄存器堆
  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wen(wen),
  .wdata(wdata),
  .waddr(rd),
  .rs1addr(rs1),
  .rs2addr(rs2),
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

  // R type instruction
  assign funct7 = inst[31:25];

  // I type instruction
  assign funct3 = inst[14:12];
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

  // S type imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Simm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:25], inst[11:7]},
                                                                1'b1, {20'hfffff, inst[31:25], inst[11:7]}
                                                              }),
                                                          .out(immS));

  // B type imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Bimm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {19'h00000, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0},
                                                                1'b0, {19'h00000, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0}
                                                              }),
                                                          .out(immB));

  // mux for adder input2(rs2data/imm)     NR_KEY , KEY_LEN , DATA_LEN 
  ysyx_24100005_MuxKeyWithDefault #(8, 7, 32) Mux_input2 (.out(add_input2), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, immI,
                                                                7'b001_0111, shiftimmU, // aipuc
                                                                7'b011_0111, shiftimmU, // lui
                                                                7'b110_1111, immJ,      // jal
                                                                7'b110_0111, immI,      // jalr
                                                                7'b000_0011, immI, // load
                                                                7'b010_0011, immS,  // store
                                                                7'b110_0011, rs2data // B type
                                                                }));

  // mux for adder input1 (rs1data/pc)
  ysyx_24100005_MuxKeyWithDefault #(7, 7, 32) Mux_input1 (.out(add_input1), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, rs1data, // partial I type
                                                                7'b001_0111, PC, // lui
                                                                7'b110_1111, PC, // jal
                                                                7'b110_0011, PC, // B type
                                                                7'b110_0111, rs1data,  // jalr
                                                                7'b000_0011, rs1data, // load
                                                                7'b010_0011, rs1data  // store
                                                                }));

  wire Cin;
  wire [31:0] t_no_Cin;
  // mux for add or sub
  ysyx_24100005_MuxKeyWithDefault #(1, 17, 1) Mux_add_sub (.out(Cin), 
                                                          .key({opcode, funct3, funct7}), 
                                                          .default_out(1'b0), 
                                                          .lut({
                                                                17'b0110011_000_0100000, 1'b1 // sub
                                                                }));

  // adder
  assign t_no_Cin = {32{ Cin }}^add_input2;
  assign add_output = add_input1 + t_no_Cin + {31'b0000, Cin};

  // assign add_output = add_input1 + add_input2;

  // write back 
  // mux for whether write back 
  ysyx_24100005_MuxKeyWithDefault #(7, 7, 1) Mux_write_reg (.out(wen), 
                                                        .key(opcode), 
                                                        .default_out(1'b0), 
                                                        .lut({
                                                              7'b110_0011, 1'b0, // B type
                                                              7'b010_0011, 1'b0,  // store
                                                              7'b110_1111, 1'b1,  // jal
                                                              7'b110_0111, 1'b1,   // jalr
                                                              7'b000_0011, 1'b1,  // load
                                                              7'b001_0011, 1'b1, // I type
                                                              7'b001_0111, 1'b1   // auipc
                                                              }));

  // mux for update PC
  ysyx_24100005_MuxKeyWithDefault #(5, 8, 32) Mux_PC (.out(DPC), 
                                                      .key({opcode, is_jump}), 
                                                      .default_out(SPC), 
                                                      .lut({
                                                            8'b110_0011_1, add_output, // B type
                                                            8'b110_1111_0, add_output,  // jal
                                                            8'b110_1111_1, add_output,  // jal
                                                            8'b110_0111_0, add_output,  // jalr                                                            
                                                            8'b110_0111_1, add_output  // jalr
                                                            }));

  wire is_jump;
  wire reduce_or;
  assign reduce_or = |add_output; // 0表示add_output为0，为1表示不为0

  // mux for whether jump
  ysyx_24100005_MuxKeyWithDefault #(9, 5, 1) Mux_jump (.out(is_jump), 
                                                      .key({funct3, reduce_or, add_output[31]}), 
                                                      .default_out(1'b0), 
                                                      .lut({
                                                            5'b000_0_0, 1'b1, // beq 只需要reduce_or=0
                                                            5'b001_1_0, 1'b1, // bnq 只需要reduce_or=1
                                                            5'b001_1_1, 1'b1, // bnq 
                                                            5'b100_1_1, 1'b1, // blt 只需要符号位为1
                                                            5'b101_0_0, 1'b1, // bge 只需要符号位为0
                                                            5'b101_1_0, 1'b1, // bge
                                                            5'b110_0_1, 1'b1, // bltu 只需要符号位为1
                                                            5'b111_0_0, 1'b1, // bgeu 只需要符号位为0
                                                            5'b111_1_0, 1'b1 // bgeu
                                                            }));


  // mux for write back in [add_output , SNPC, mem_read_res]
  ysyx_24100005_MuxKeyWithDefault #(3, 7, 32) Mux_writedata (.out(wdata), 
                                                              .key(opcode), 
                                                              .default_out(add_output), 
                                                              .lut({
                                                                    7'b110_1111, SPC,  // jal
                                                                    7'b110_0111, SPC,  // jalr   
                                                                    7'b000_0011, mem_read_res  // load
                                                                    }));

  // mux for whether load
  ysyx_24100005_MuxKeyWithDefault #(2, 7, 1) Mux_read_mem (.out(read_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b1,  // load
                                                                    7'b010_0011,  1'b0  // store                                                           
                                                                    }));


  // mux for whether store
  ysyx_24100005_MuxKeyWithDefault #(2, 7, 1) Mux_write_mem (.out(write_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b0,  // load
                                                                    7'b010_0011,  1'b1  // store                                                           
                                                                    }));

  // memory read extract 通过阅读汇编知道，lb地址是字节对齐，lh地址是双字节对齐，lw地址是四字节对齐
  ysyx_24100005_MuxKeyWithDefault #(13, 5, 32) Mux_mem_read_extract(.key({funct3, add_output[1:0]}),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                // lb
                                                                5'b000_00, {24'h000000, mem_rdata[7:0]},
                                                                5'b000_01, {24'h000000, mem_rdata[15:8]},
                                                                5'b000_10, {24'h000000, mem_rdata[23:16]},
                                                                5'b000_11, {24'h000000, mem_rdata[31:24]},
                                                                // lh|lhu
                                                                5'b001_00, {16'h000000, mem_rdata[15:0]},
                                                                5'b001_10, {16'h000000, mem_rdata[31:16]},
                                                                // lw
                                                                5'b010_00, mem_rdata[31:0],
                                                                // lbu
                                                                5'b011_00, {24'h000000, mem_rdata[7:0]},
                                                                5'b011_01, {24'h000000, mem_rdata[15:8]},
                                                                5'b011_10, {24'h000000, mem_rdata[23:16]},
                                                                5'b011_11, {24'h000000, mem_rdata[31:24]},
                                                                // lhu
                                                                5'b100_00, {16'h000000, mem_rdata[15:0]},
                                                                5'b100_10, {16'h000000, mem_rdata[31:16]}
                                                              }),
                                                          .out(mem_extract));
  // memory read LB sign extend  
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Mux_lb_sext(.key(mem_extract[7]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {24'h000000, mem_rdata[7:0]},
                                                                1'b1, {24'hffffff, mem_rdata[7:0]}
                                                              }),
                                                          .out(mem_lb_sext));

// memory read LH sign extend  
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Mux_lh_sext(.key(mem_extract[15]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {16'h0000, mem_rdata[15:0]},
                                                                1'b1, {16'hffff, mem_rdata[15:0]}
                                                              }),
                                                          .out(mem_lh_sext));

  assign mem_no_sext = mem_rdata;
  // memory read res 
  ysyx_24100005_MuxKeyWithDefault #(5, 3, 32) Mux_mem_read(.key(funct3),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                3'b000, mem_lb_sext, // lb
                                                                3'b001, mem_lh_sext, // lh
                                                                3'b010, mem_no_sext, // lw
                                                                3'b011, mem_no_sext, // lbu
                                                                3'b100, mem_no_sext  // lhu
                                                              }),
                                                          .out(mem_read_res));
  // assign mem_read_res = 32'h0000_0001;

// memory write mask
  ysyx_24100005_MuxKeyWithDefault #(7, 5, 8) Mux_wmask(.key({funct3, add_output[1:0]}),
                                                          .default_out({8'b0000_0000}),
                                                          .lut({
                                                                5'b000_00, {8'b0000_0001}, // sb
                                                                5'b000_01, {8'b0000_0010}, // sb
                                                                5'b000_10, {8'b0000_0100}, // sb
                                                                5'b000_11, {8'b0000_1000}, // sb

                                                                5'b001_00, {8'b0000_0011}, // sb
                                                                5'b001_10, {8'b0000_1100}, // sb

                                                                5'b010_00, {8'b0000_1111} // sw
                                                              }),
                                                          .out(wmask));

  // assign wmask = 8'b00000001;
  // memory access
  // 为什么add_output变化会触发两次，因为第一次触发是下降沿rs1addr变了，
  // 第二次触发时上升沿rs1addr变了，所以add_output会变化两次

  always @(PC) begin
    if( PC != 0) begin
      inst = npcmem_read(PC);
    end
    else begin
      inst = 0;
    end
  end


  always @(read_mem, add_output, write_mem, rs2data, wmask) begin

    if (read_mem ) begin // 
      mem_rdata = npcmem_read(add_output);
    end
    else begin 
      mem_rdata = 0;
    end
    
    if (write_mem) begin // 有写请求时
        npcmem_write(add_output, rs2data, wmask);
      end
  end

  // // ebreak
  always @(opcode) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

  // always @(posedge clk) begin
  //   $display("inst=%h, ", inst);
  //   $display("tmp=%h, ", tmp);
  //   $display("Opcode=%h, ", opcode);
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