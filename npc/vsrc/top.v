import "DPI-C" function void ebreak();
module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] SPC;
  wire [31:0] DPC;

  wire wen;
  wire [31:0] wdata;
  wire [31:0] rdata;

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
  .wdata(add_output),
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
  // stact next pc
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
                                                                1'b0, {12'h000, inst[31], inst[19:12], inst[20], inst[30:21]},
                                                                1'b1, {12'h000, inst[31], inst[19:12], inst[20], inst[30:21]}
                                                              }),
                                                          .out(immJ));


  // mux for adder input2(imm)     NR_KEY , KEY_LEN , DATA_LEN 
  ysyx_24100005_MuxKeyWithDefault #(4, 7, 32) Mux_input2 (.out(add_input2), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, immI,
                                                                7'b001_0111, shiftimmU, // aipuc
                                                                7'b011_0111, shiftimmU, // lui
                                                                7'b110_1111, immJ       // jal
                                                                }));

  // mux for adder input1 (reg/pc)
  ysyx_24100005_MuxKeyWithDefault #(2, 7, 32) Mux_input1 (.out(add_input1), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, rdata,
                                                                7'b001_0111, PC // lui
                                                                }));



  // assign wdata = rdata + {20'd0, imm};
  assign add_output = add_input1 + add_input2;

  // write back 
  // mux for adder input 1 
  ysyx_24100005_MuxKeyWithDefault #(4, 7, 1) Mux_write (.out(wen), 
                                                        .key(opcode), 
                                                        .default_out(1'b1), 
                                                        .lut({
                                                              7'b110_0011, 1'b0, // B type
                                                              7'b010_0011, 1'b0,  // S type
                                                              7'b110_1111, 1'b0,  // jal
                                                              7'b110_0111, 1'b0  // jalr
                                                              }));

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


  // ebreak
  always @(*) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

  always @(posedge clk) begin
    $display("inst=%h, ", inst);
    $display("Opcode=%h, ", opcode);
  end

endmodule
