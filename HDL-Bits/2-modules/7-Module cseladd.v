module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire cin1,cin2,cin3,cout1,cout2,cout3;
    wire [15:0] sum1,sum2,sum3;
    assign cin1 = 1'b0;
    assign cin2 = 1'b0;
    assign cin3 = 1'b1;
    add16 add1 (a[15:0],b[15:0],cin1,sum1,cout1);
    add16 add2 (a[31:16],b[31:16],cin2,sum2,cout2);
    add16 add3 (a[31:16],b[31:16],cin3,sum3,cout3);
    
    always@(*)
        begin
        	case(cout1)
                1'b0:sum={sum2,sum1};
                1'b1:sum={sum3,sum1};
            endcase
        end
endmodule
