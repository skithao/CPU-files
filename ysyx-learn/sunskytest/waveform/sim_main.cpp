#include <memory>
#include <verilated.h>
#include "Vedge_detect.h"
#include "verilated_vcd_c.h"

double sc_time_stamp() { return 0; }

int main(int argc, char **argv)
{
    // 处理命令行参数
    Verilated::commandArgs(argc, argv);
    
    // 创建上下文
    auto contextp = std::make_unique<VerilatedContext>();
    contextp->debug(0);
    contextp->randReset(2);
    contextp->traceEverOn(true); // 启用波形跟踪

    // 创建顶层模块实例
    auto top = std::make_unique<Vedge_detect>(contextp.get(), "TOP");

    // 创建 VCD 记录器
    std::unique_ptr<VerilatedVcdC> tfp(new VerilatedVcdC);
    top->trace(tfp.get(), 0); // 设置跟踪的精度

    // 打开 VCD 文件，如果打开失败，则输出错误信息并返回
    tfp->open("wave.vcd");
    if (!tfp->isOpen()) { // 检查文件是否成功打开
        fprintf(stderr, "Error opening VCD file.\n");
        return -1; // 打开文件失败，返回错误
    }

    // 初始化信号
    top->rst_n = 0;
    top->clk = 0;
    top->a = 0;

    // 仿真过程
    while (!contextp->gotFinish())
    {
        // 更新时间
        contextp->timeInc(1);
        top->clk = !top->clk; // 切换时钟信号

        if (!top->clk) // 每个时钟周期的下降沿
        {
            // 设定复位信号
            top->rst_n = (contextp->time() >= 10) ? 1 : 0; 

            // 控制输入信号 a
            if (contextp->time() >= 15) {
                top->a = (contextp->time() < 30) ? (contextp->time() >= 20) : (contextp->time() < 40) ? 0 : top->a; 
            }

            // 终止条件
            if (contextp->time() >= 3000) {
                break;
            }
        }

        // 评估模块
        top->eval();
        tfp->dump(contextp->time()); // 转储波形数据

        // 打印信号状态
        VL_PRINTF("[%" PRId64 "] clk=%x rst_n=%x a=%x rise=%x down=%x \n", 
            contextp->time(), top->clk, top->rst_n, top->a, top->rise, top->down);
    }

    // 完成仿真
    top->final();
    tfp->close(); // 关闭 VCD 文件
    return 0;
}
