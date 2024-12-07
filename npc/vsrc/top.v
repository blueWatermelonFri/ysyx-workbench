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
  wire [4:0] rd;

  wire [31:0] immI_1;
  wire [31:0] immI_2;
  wire [31:0] immI;
  wire [31:0] immI;
  wire [31:0] immJ;
  wire [31:0] immU;
  wire [31:0] immS;
  wire [31:0] immB;

  //logic/adder input
  wire [31:0] add_input1;
  wire [31:0] add_input2;

  //adder output
  wire [31:0] adder_output;
  
  // logic output
  wire [31:0] xor_output ;
  wire [31:0] or_output ;
  wire [31:0] and_output ;
  wire [31:0] sll_output ;
  wire [31:0] srl_output ;
  wire [31:0] sra_output ;
  wire [31:0] slt_slti_output ;
  wire [31:0] sltu_sltiu_output ;

  wire [31:0] logic_output ;
  wire [31:0] shift_output ;
  wire [31:0] RI_output ;

  //pc  adder input output
  wire [31:0] pc_input1;
  wire [31:0] pc_input2;
  wire [31:0] pc_adder_ouptut;

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
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Iimm_SEXT_1(.key(inst[31]),
                                                          .default_out({32'h0}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:20]},
                                                                1'b1, {20'hfffff, inst[31:20]}
                                                              }),
                                                          .out(immI_1));

  ysyx_24100005_MuxKeyWithDefault #(2, 3, 32) Iimm_SEXT_2(.key(funct3),
                                                          .default_out({32'h0}),
                                                          .lut({
                                                                3'b001, {27'h00000, inst[24:20]},
                                                                3'b101, {27'h00000, inst[24:20]}
                                                              }),
                                                          .out(immI_2));

  ysyx_24100005_MuxKeyWithDefault #(2, 3, 32) Iimm_SEXT(.key(funct3),
                                                          .default_out(immI_1),
                                                          .lut({
                                                                3'b001, immI_2,
                                                                3'b101, immI_2
                                                              }),
                                                          .out(immI));

  // U type instruction imm extension
  assign immU = {inst[31:12], 12'h000};

  // j type instruction
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Jimm_SEXT (.key(inst[31]),
                                                          .default_out({32'h0}),
                                                          .lut({
                                                                1'b0, {11'h000, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0},
                                                                1'b1, {11'hfff, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}
                                                              }),
                                                          .out(immJ));

  // S type imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Simm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:25], inst[11:7]},
                                                                1'b1, {20'hfffff, inst[31:25], inst[11:7]}
                                                              }),
                                                          .out(immS));

  // B type imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Bimm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0}),
                                                          .lut({
                                                                1'b0, {19'h00000, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0},
                                                                1'b1, {19'h7ffff, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0}
                                                              }),
                                                          .out(immB));

  // mux for adder input1 (rs1data/pc)
  assign add_input1 = rs1data;

  // mux for adder input2(rs2data/imm)     NR_KEY , KEY_LEN , DATA_LEN 
  ysyx_24100005_MuxKeyWithDefault #(9, 7, 32) Mux_input2 (.out(add_input2), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, immI,
                                                                7'b001_0111, immU, // aipuc
                                                                7'b011_0111, immU, // lui
                                                                7'b110_1111, immJ,      // jal
                                                                7'b110_0111, immI,      // jalr
                                                                7'b000_0011, immI, // load
                                                                7'b010_0011, immS,  // store
                                                                7'b011_0011, rs2data,  // R type
                                                                7'b110_0011, rs2data   // B type
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
  assign adder_output = add_input1 + t_no_Cin + {31'b0000, Cin};

  // logic
  assign xor_output = add_input1 ^ add_input2;
  assign or_output = add_input1 | add_input2;
  assign and_output = add_input1 & add_input2;
  assign slt_slti_output = is_jump == 1? 1: 0;
  assign sltu_sltiu_output = is_jump == 1? 1: 0;

  // shift
  assign sll_output = add_input1 << add_input2;
  assign srl_output = add_input1 >> add_input2;
  assign sra_output = add_input1 >>> add_input2;

  ysyx_24100005_MuxKeyWithDefault #(5, 3, 32) Mux_logic_output (.out(logic_output), 
                                                        .key(funct3), 
                                                        .default_out(32'b0), 
                                                        .lut({
                                                              3'b100, xor_output, // B type
                                                              3'b110, or_output,  // store
                                                              3'b111, and_output,  // jal
                                                              3'b010, slt_slti_output,   // jalr
                                                              3'b011, sltu_sltiu_output   // jalr
                                                              }));

  ysyx_24100005_MuxKeyWithDefault #(3, 10, 32) Mux_shift_output (.out(shift_output), 
                                                        .key({funct3, funct7}), 
                                                        .default_out(32'b0), 
                                                        .lut({
                                                              10'b001_0000000, sll_output, // B type
                                                              10'b101_0000000, srl_output, // B type
                                                              10'b101_0100000, sra_output  // B type
                                                              }));

  // write back 
  // mux for whether write back 
  ysyx_24100005_MuxKeyWithDefault #(7, 7, 1) Mux_write_reg (.out(wen), 
                                                        .key(opcode), 
                                                        .default_out(1'b0), 
                                                        .lut({
                                                              7'b011_0011, 1'b1,  // R type
                                                              7'b001_0011, 1'b1, // I type
                                                              7'b000_0011, 1'b1,  // load
                                                              7'b110_1111, 1'b1,  // jal
                                                              7'b110_0111, 1'b1,   // jalr
                                                              7'b011_0111, 1'b1,   // lui
                                                              7'b001_0111, 1'b1   // auipc
                                                              }));
  // mux for whether PC adder input1(PC/rs1) 
  ysyx_24100005_MuxKeyWithDefault #(4, 7, 32) Mux_PC_input1 (.out(pc_input1), 
                                                        .key(opcode), 
                                                        .default_out(32'b0), 
                                                        .lut({
                                                              7'b110_0011, PC, // B type
                                                              7'b110_1111, PC,  // jal
                                                              7'b110_0111, rs1data,   // jalr
                                                              7'b001_0111, PC   // auipc
                                                              }));

  // mux for whether PC adder input2(imm) 
  ysyx_24100005_MuxKeyWithDefault #(4, 7, 32) Mux_PC_input2 (.out(pc_input2), 
                                                        .key(opcode), 
                                                        .default_out(32'b0), 
                                                        .lut({
                                                              7'b110_0011, immB, // B type
                                                              7'b110_1111, immJ,  // jal
                                                              7'b110_0111, immI,   // jalr
                                                              7'b001_0111, immU   // auipc
                                                              }));

  assign pc_adder_ouptut = pc_input1 + pc_input2;
  
  // mux for update PC
  ysyx_24100005_MuxKeyWithDefault #(5, 8, 32) Mux_PC (.out(DPC), 
                                                      .key({opcode, is_jump}), 
                                                      .default_out(SPC), 
                                                      .lut({
                                                            8'b110_0011_1, pc_adder_ouptut, // B type
                                                            8'b110_1111_0, pc_adder_ouptut,  // jal
                                                            8'b110_1111_1, pc_adder_ouptut,  // jal
                                                            8'b110_0111_0, pc_adder_ouptut,  // jalr                                                            
                                                            8'b110_0111_1, pc_adder_ouptut  // jalr
                                                            }));
  
  // 比较器
  wire is_jump;                // is_jump为1表示比较器的结果为真
  wire zero;
  wire carry;
  wire overflow;

  wire is_equal;
  wire is_lt;
  wire is_gt;
  wire is_ltu;
  wire is_gtu;

  wire [31:0] jump_t_no_Cin;
  wire [31:0] jump_data;

  assign jump_t_no_Cin = {32{ 1'b1 }}^add_input2;
  assign {carry, jump_data} = add_input1 + jump_t_no_Cin + {32'b0000, 1'b1};
  assign zero = |jump_data; // zero = 0表示a=b
  assign overflow = (add_input1[31] == jump_t_no_Cin[31]) && (jump_data [31] != add_input1[31]);

  // 借位标志 borrow 由加法操作中的进位标志 cout 来确定：
  // 借位发生时：carry = 0，borrow = 1，表示 A < B。
  // 没有借位时：carry = 1，borrow = 0，表示 A >= B。
  assign is_equal = zero;
  assign is_lt = (overflow == 0 && jump_data[31] == 1) || (overflow == 1 && add_input1[0] == 1);
  assign is_gt = (overflow == 0 && jump_data[31] == 0) || (overflow == 1 && add_input1[0] == 0); //严格大于，不包括等于
  assign is_ltu = carry == 0 ;
  assign is_gtu = carry == 1 ; //严格大于，不包括等于


  // mux for whether jump
  // slt/slti的判断逻辑是一样的，所以共用一套条件，这也是为什么slt和slt的funct3是相同的，sltu/sltiu同理
  ysyx_24100005_MuxKeyWithDefault #(19, 8, 1) Mux_jump (.out(is_jump), 
                                                      .key({funct3, is_equal, is_lt, is_gt, is_ltu, is_gtu}), 
                                                      .default_out(1'b0), 
                                                      .lut({
                                                            8'b000_00000, 1'b1, // beq zero = 0
                                                            8'b001_11001, 1'b1, // bne zero != 0
                                                            8'b001_11010, 1'b1, // bne zero != 0
                                                            8'b001_10101, 1'b1, // bne zero != 0
                                                            8'b001_10110, 1'b1, // bne zero != 0
                                                            8'b100_10110, 1'b1, // blt zero = 1, is_lt = 1, is_gt = 0
                                                            8'b100_10101, 1'b1, // blt 
                                                            8'b101_01001, 1'b1, // bge is_lt = 0, is_gt = 1
                                                            8'b101_01010, 1'b1, // bge 
                                                            8'b101_11001, 1'b1, // bge 
                                                            8'b101_11010, 1'b1, // bge 
                                                            8'b110_11010, 1'b1, // bltu zero = 1, is_ltu = 1, is_gt = 0
                                                            8'b110_10110, 1'b1, // bltu 
                                                            8'b111_00101, 1'b1, // bgeu is_ltu = 0, is_gtu = 1
                                                            8'b111_01001, 1'b1, // bgeu is_ltu = 0, is_gtu = 1
                                                            8'b010_11010, 1'b1, // slt/slti  zero = 0, is_lt = 1, is_gt = 0
                                                            8'b010_11001, 1'b1, // 
                                                            8'b011_11010, 1'b1, // sltu/sltiu zero = 0, is_ltu = 1, is_gtu = 0
                                                            8'b011_10110, 1'b1 // 
                                                            }));

  // mux for write data  in [R type | partial I tyep]
  ysyx_24100005_MuxKeyWithDefault #(8, 3, 32) Mux_RI_output (.out(RI_output), 
                                                              .key({funct3}), 
                                                              .default_out(32'b0), 
                                                              .lut({
                                                                    3'b000, adder_output,  // add sub addi
                                                                    3'b100, logic_output,  // xor xori
                                                                    3'b110, logic_output,  // or ori
                                                                    3'b111, logic_output,  // and andi
                                                                    3'b010, logic_output,  // slt slti
                                                                    3'b011, logic_output,  // sltu sltiu
                                                                    3'b001, shift_output,  // sll slli
                                                                    3'b101, shift_output  // srl sra srli srai
                                                                    }));



  // mux for write back in [RI_output , SNPC, mem_read_res,  immU, pc_adder_ouptut]
  ysyx_24100005_MuxKeyWithDefault #(7, 7, 32) Mux_writedata (.out(wdata), 
                                                              .key(opcode), 
                                                              .default_out(32'b0), 
                                                              .lut({
                                                                    7'b011_0011, RI_output,  // R   
                                                                    7'b001_0011, RI_output,  // partial I
                                                                    7'b000_0011, mem_read_res,  // load
                                                                    7'b110_1111, SPC,  // jal
                                                                    7'b110_0111, SPC,  // jalr   
                                                                    7'b011_0111, immU,  // lui
                                                                    7'b001_0111, pc_adder_ouptut  // auipc
                                                                    }));

  // mux for whether load
  ysyx_24100005_MuxKeyWithDefault #(1, 7, 1) Mux_read_mem (.out(read_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b1  // load
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
  ysyx_24100005_MuxKeyWithDefault #(13, 5, 32) Mux_mem_read_extract(.key({funct3, adder_output[1:0]}),
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
                                                                5'b100_00, {24'h000000, mem_rdata[7:0]},
                                                                5'b100_01, {24'h000000, mem_rdata[15:8]},
                                                                5'b100_10, {24'h000000, mem_rdata[23:16]},
                                                                5'b100_11, {24'h000000, mem_rdata[31:24]},
                                                                // lhu
                                                                5'b101_00, {16'h000000, mem_rdata[15:0]},
                                                                5'b101_10, {16'h000000, mem_rdata[31:16]}
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
  ysyx_24100005_MuxKeyWithDefault #(7, 5, 8) Mux_wmask(.key({funct3, adder_output[1:0]}),
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


  always @(read_mem, adder_output, write_mem, rs2data, wmask) begin

    $display("mem rdata = %h", read_mem);
    $display("mem rdata = %h", mem_rdata);
    if (read_mem ) begin // 
      mem_rdata = npcmem_read(adder_output);
    end
    else begin 
      mem_rdata = 0;
    end
    
    if (write_mem) begin // 有写请求时
        npcmem_write(adder_output, rs2data, wmask);
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