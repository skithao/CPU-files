module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//

    wire cin;
    wire cout1;
    wire cout2;
    wire [15:0] sum1,sum2;
    
    assign cin = 1'b0;
    add16 instance0 (a[15:0],b[15:0],cin,sum1,cout1);
    add16 instance1 (a[31:16],b[31:16],cout1,sum2,cout2);
    assign sum = {sum2,sum1};
    
endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );

// Full adder module here
    assign sum = a^b^cin;
    assign cout = a&b | a&cin | b&cin;

endmodule
