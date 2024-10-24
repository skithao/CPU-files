module top_module ( input clk, input d, output q );
    wire q1_wire;
    wire q2_wire;
    my_dff instance4 (.clk(clk),.d(d),.q(q1_wire));
    my_dff instance5 (.clk(clk),.d(q1_wire),.q(q2_wire));
    my_dff instance6 (.clk(clk),.d(q2_wire),.q(q));
       
endmodule
