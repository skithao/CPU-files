module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire cin;
    wire [15:0] sum1,sum2;
    wire cout1,cout2;
    assign cin = 1'b0;
    add16 instance1 (.a(a[15:0]),.b(b[15:0]),.cin(cin),.sum(sum1),.cout(cout1));
    add16 instance2 (.a(a[31:16]),.b(b[31:16]),.cin(cout1),.sum(sum2),.cout(cout2));
    assign sum = {sum2,sum1};
    
endmodule
