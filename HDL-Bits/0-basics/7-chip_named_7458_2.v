module top_module ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );
    
    wire p3y = (p1f & p1e & p1d);
    wire p4y = (p1a & p1c & p1b);
    wire p5y = (p2c & p2d);
    wire p6y = (p2a & p2b);
    
    assign p1y = p3y|p4y;
    assign p2y = p5y|p6y;
    
endmodule