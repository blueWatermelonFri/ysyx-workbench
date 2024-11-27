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
  .wdata(wdata),
  .waddr(rd),
  .rs1addr(rs1),
  .rs2addr(rs2),
  .wen(wen),
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
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Iimm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:20]},
                                                                1'b1, {20'hfffff, inst[31:20]}
                                                              }),
                                                          .out(immI));

  // S type imm extension
  ysyx_24100005_MuxKeyWithDefault #(2, 1, 32) Simm_SEXT(.key(inst[31]),
                                                          .default_out({32'h0000_0000}),
                                                          .lut({
                                                                1'b0, {20'h00000, inst[31:25], inst[11:7]},
                                                                1'b1, {20'hfffff, inst[31:25], inst[11:7]}
                                                              }),
                                                          .out(immS));

  // mux for adder input2(imm)     NR_KEY , KEY_LEN , DATA_LEN 
  ysyx_24100005_MuxKeyWithDefault #(1, 7, 32) Mux_input2 (.out(add_input2), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, immI
                                                                // 7'b000_0011, immI, // load
                                                                // 7'b010_0011, immS  // store                                                                
                                                                }));

  // mux for adder input1 (reg/pc)
  ysyx_24100005_MuxKeyWithDefault #(4, 7, 32) Mux_input1 (.out(add_input1), 
                                                          .key(opcode), 
                                                          .default_out(32'h0), 
                                                          .lut({
                                                                7'b001_0011, rs1data, // partial I type
                                                                7'b001_0111, PC, // lui
                                                                7'b110_1111, PC, // jal
                                                                7'b110_0111, rs1data  // jalr
                                                                // 7'b000_0011, rs1data, // load
                                                                // 7'b010_0011, rs1data // store
                                                                }));

  assign add_output = add_input1 + add_input2;

  assign DPC = 32'h8000_0000;

  assign wdata = 0;

  // assign write_mem = 0;
  wire tmp ;
  ysyx_24100005_MuxKeyWithDefault #(1, 7, 1) Mux_read_mem (.out(read_mem), 
                                                              .key(opcode), 
                                                              .default_out(1'b0), 
                                                              .lut({
                                                                    7'b000_0011,  1'b0  // load
                                                                    // 7'b010_0011,  1'b1  // store                                                           
                                                                    }));

  assign tmp = 0;


// 1. 把read换为tmp就不会段错误了
// 2. 每一个周期会打印好几次
// 3. 尝试一个最小的可复现demo
// 4. 为什么每个posedge会变化两次
  assign wmask = 8'b00000001;
  // memory access
  always @(*) begin

    // $display("read_mem       =%h", 0);
    $display("inst       =%h", inst);

    if (read_mem) begin // 有读写请求时 // 可以进一步优化吗，因为代码的逻辑是要写的话就必须读
      mem_rdata = npcmem_read(add_output);
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
  //   $display("tmp=%h, ", tmp);
  //   $display("Opcode=%h, ", opcode);
  //   $display("PC=%h, ", PC);
  //   $display("add1=%h, ", add_input1);
  //   $display("add2=%h, ", add_input2);
  // end

endmodule

