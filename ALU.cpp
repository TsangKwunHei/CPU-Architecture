
/*
- ADD, MINUS, AND, OR

1 Simple Input Output
2 Turn binary

*/


int ALU(String Operand, int x1, int x2 )
    int x3;
    if Operand == 'ADD' 
        x3 = x2 + x1;
    if Operand == 'MINUS'   
        x3 = x2 - x1;  
    if Operand == 'AND' 
        x3 = x2 && x1;  
    if Operand == 'OR' 
        x3 = x2 - x1;  

    return x3;


