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
  wire vaild; // mem read
  wire write_mem; // mem write
  wire [31:0] wdata; // reg write
  wire [31:0] rs1data; // reg read rs1
  wire [31:0] rs2data; // reg read rs2

  // for mem read extract and sext
  reg [31:0] mem_rdata;

  wire [6:0] opcode;
  wire [2:0] funct3;
  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [4:0] rd;


  // adder input output
  wire [31:0] addr;
  wire [31:0] add_input1;
  wire [31:0] add_input2;


  // PC更新
  ysyx_24100005_Reg #(32, 32'h8000_0000) i0 (.clk(clk),
                                              .rst(rst), 
                                              .din(DPC), 
                                              .dout(PC), 
                                              .wen(1'b1));
  // static next pc
  assign SPC = PC + 32'h0000_0004;

  assign rs1 = inst[19:15];
  assign rs2 = inst[24:20];
  assign opcode = inst[6:0];
  assign rd = inst[11:7];
  assign funct3 = inst[14:12];
  assign wdata = 0;

  // 初始化寄存器堆
  ysyx_24100005_RegisterFile #(5, 32) RegFile(
  .clk(clk),
  .wdata(wdata),
  .waddr(rd),
  .rs1addr(rs1),
  .rs2addr(rs2),
  .wen(wen),
  .rs1data(rs1data),
  .rs2data(rs2data)
  );

  assign DPC = 32'h8000_0000;



  assign add_input1 = 32'h0;
  assign add_input1 = 32'h0;

  assign addr = add_input1 + add_input2;

  // 判断指令是否有读写需求
  ysyx_24100005_MuxKeyWithDefault #(1, 7, 1) Mux_read_mem (.out(vaild), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b1  // load
                                                                    }));

  always @(*) begin


    if (vaild) begin // 有读写请求时 
      mem_rdata = npcmem_read(addr);
    end
    else begin
      mem_rdata = 0;
    end
  end



endmodule

