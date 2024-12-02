import "DPI-C" function void ebreak();

module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] SPC;
  wire [31:0] DPC;
  wire [31:0] rs1data; // reg read rs1
  wire [31:0] rs2data; // reg read rs2
  wire [6:0] opcode;

  // 初始化寄存器堆
  always @(posedge clk) begin
    if (rst) PC <= 32'h0;
    else PC <= SPC;
  end

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

  always @(posedge clk) begin
    if (rst) PC <= 32'h8000_0000;
    else  PC <= PC + 32'h4;
  end


  // static next pc
  assign SPC = PC + 32'h0000_0004;

  assign opcode = inst[6:0];

  // assign DPC = SPC;

  // mux for update PC
  // ysyx_24100005_MuxKeyWithDefault #(5, 7, 32) Mux_PC (.out(DPC), 
  //                                                     .key(opcode), 
  //                                                     .default_out(SPC), 
  //                                                     .lut({
  //                                                           7'b011_0011, SPC,         // R type
  //                                                           7'b001_0011, SPC,         // partial I type
  //                                                           7'b000_0011, SPC,         // load
  //                                                           7'b010_0011, SPC,         // store
  //                                                           7'b011_0111, SPC          // U type
  //                                                           }));

  // ebreak
  always @(*) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

endmodule