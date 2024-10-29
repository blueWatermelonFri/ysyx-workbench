module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] Next_PC;
  wire [6:0] Opcode;
  wire [2:0] funct3;
  wire [4:0] rs1;
  wire [11:0] imm;
  wire [4:0] rd;

  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk), 
                                              .rst(rst), 
                                              .din(Next_PC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  assign Next_PC = PC + 32'h0000_0004;
  assign Opcode = inst[6:0];
  assign funct3 = inst[14:12];
  assign rs1 = inst[19:15];
  assign imm = inst[31:20];
  assign rd = inst[11:7];








  always @(posedge clk) begin
    $display("inst=%h, ", inst);
    $display("Opcode=%h, ", Opcode);

  end

endmodule