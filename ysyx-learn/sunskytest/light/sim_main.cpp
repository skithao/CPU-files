#include <iostream>
#include "verilated.h"
#include "Vlight.h"

// 使用 Verilator 库模拟 light 模块
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vlight* top = new Vlight; // 实例化 light 模块

    // 初始化
    top->clk = 0;
    top->rst = 1; // 初始复位信号为高

    // 模拟复位过程
    top->eval();
    top->rst = 0; // 释放复位信号
    top->eval();

    // 翻转一次时钟以确保设计在释放复位后的正确状态
    top->clk = 1;
    top->eval();
    top->clk = 0;
    top->eval();

    // 主仿真循环
    for (int i = 0; i < 200; ++i) { // 增加循环次数以观察长时间变化
        top->clk = !top->clk; // 翻转时钟信号
        
        // 模拟时钟上升沿
        top->eval();
        
        // 打印当前 LED 状态
        std::cout << "Time: " << i << ", LED: " << (int)top->led << std::endl; 
        // 将 led 转为 int 输出

        // 适当延迟
        for (volatile int j = 0; j < 100000; ++j);
    }

    // 清理
    delete top;
    return 0;
}
