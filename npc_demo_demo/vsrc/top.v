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
                                              .wen(clk));
  // static next pc
  assign SPC = PC + 32'h0000_0004;



  assign opcode = inst[6:0];

  // mux for update PC

  assgin DPC = SPC;

  // ebreak
  always @(*) begin
    if(opcode == 7'b1110011) begin
      ebreak();
    end
  end

endmodule