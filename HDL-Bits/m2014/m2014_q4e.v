module top_module (
    input in1,
    input in2,
    output out);

    wire nor_out = ~(in1 | in2);
    assign out = nor_out;

endmodule
