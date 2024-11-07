import "DPI-C" function void add();
module ysyx_24100005_top(
  input [31:0] inst,
  input rst,
  input clk,

  output reg [31:0] PC
);
  wire [31:0] Next_PC;
  wire [31:0] wdata;
  wire [31:0] rdata;

  wire [6:0] Opcode;
  wire [2:0] funct3;
  wire [4:0] rs1;
  wire [11:0] imm;
  wire [4:0] rd;

  // 初始化寄存器堆
  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wdata(wdata),
  .waddr(rd),
  .raddr(rs1),
  .wen(1'b1),
  .rdata(rdata)
  );

  // 取值
  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk), 
                                              .rst(rst), 
                                              .din(Next_PC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  assign Next_PC = PC + 32'h0000_0004;

  // 译码
  assign Opcode = inst[6:0];
  assign funct3 = inst[14:12];
  assign rs1 = inst[19:15];
  assign imm = inst[31:20];
  assign rd = inst[11:7];


  assign wdata = rdata + {20'd0, imm};


  always @(*) begin
    if(Opcode == 7'b1110011) begin
      add();
    end
  end




  // 执行
  always @(posedge clk) begin
    $display("inst=%h, ", inst);
    $display("Opcode=%h, ", Opcode);
  end

endmodule
