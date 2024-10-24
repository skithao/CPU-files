#.PHONY: sim_wave

sim_wave:
	verilator -Wall --trace -cc -exe edge_detect.v sim_main.cpp