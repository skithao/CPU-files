#!/bin/bash

# 设置参数
BASE_DIR="/home/sunsky/codes/CPU-files/ysyx-learn/sunskytest/waveform"
V_FILE="edge_detect.v"
CPP_FILE="sim_main.cpp"
OBJ_DIR="./obj_dir"
MK_FILE="Vedge_detect.mk"
TOP_MODULE="Vedge_detect"
VCD_FILE="${BASE_DIR}/wave.vcd"

# 切换到默认路径
cd "$BASE_DIR" || { echo "路径不存在"; exit 1; }

echo "欢迎使用 Sunsky-Verilator 模拟工具 -- $V_FILE ！"
echo "请选择您要执行的操作："
echo "1) 清理"
echo "2) 编译"
echo "3) 运行"
echo "4) 波形"
echo "5) 退出"

while true; do
    read -p "请输入您的选择 (1-5): " choice
    case $choice in
        1)
            echo "正在清理对象目录..."
            sudo rm -rf "$OBJ_DIR"
            echo "清理完成！"
            ;;
        2)
            echo "正在编译..."
            verilator -Wall --cc -O3 --trace --build "$V_FILE" --exe "$CPP_FILE"
            echo "编译完成！"
            ;;
        3)
            echo "正在运行模拟程序..."
            make -C "$OBJ_DIR" -f "$MK_FILE"  -j $(nproc) "$TOP_MODULE"
            echo "正在启动 Verilator 仿真..."
            sudo chmod +x ./obj_dir/"$TOP_MODULE"
            ./obj_dir/"$TOP_MODULE"
            echo "模拟程序已运行！"
            ;;
        4)
            if [ -f "$VCD_FILE" ]; then
                echo "正在使用 GTKwave 查看 $VCD_FILE..."
                gtkwave "$VCD_FILE"
                echo "GTKwave 已启动！"
            else
                echo "错误：未找到 $VCD_FILE 文件！请确认是否已生成波形文件。"
            fi
            ;;
        5)
            echo "退出脚本。"
            break
            ;;
        *)
            echo "无效选择，请重试！"
            ;;
    esac
done