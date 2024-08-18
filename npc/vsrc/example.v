module example(
        input a,
        input b,
        output f
    );
    assign f = a ^ b;

	initial begin
		$dumpfile("dump"); // 指定输出的 VCD 文件名
		$dumpvars(0, top_module); // 指定从哪个模块开始记录波形
	end
endmodule
