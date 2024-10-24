module light( // 定义一个名为light的模块
  input clk, // 输入时钟信号
  input rst, // 输入复位信号
  output reg [15:0] led // 输出16位LED状态
);
  reg [31:0] count; // 计数器，用于控制LED状态的变化
  always @(posedge clk) begin // 在时钟上升沿触发
    if (rst) begin led <= 1; count <= 0; end // 复位时，将LED设为1，并重置计数器
    else begin
      if (count == 0) led <= {led[14:0], led[15]}; // 当计数器为0时，循环移位LED状态
      count <= (count >= 5000000 ? 32'b0 : count + 1); // 更新计数器，达到阈值后重置
    end
  end
endmodule
