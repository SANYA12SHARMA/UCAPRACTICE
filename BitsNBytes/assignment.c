/* bitAnd - x & y using only ~ and |
   Example bitAnd(6, 5) = 4
   Legal ops:  ~ |  
   Max ops: 8
*/
int bitAnd (int x, int y) {
     int bitsAnd = ~(~x | ~y);
     return bitsAnd;
}
/* bitXor - x ^ y using only ~ and &
   Example bitXor(4, 5) = 1
   Legal ops:  ~ &  
   Max ops: 14
*/
int bitXor (int x, int y) {
    int bitsOr = ~(~x & ~y);
    int bitsAnd = x & y;
    int bitsXor = bitsOr & ~(bitsAnd);
    return bitsXor;
}
/* sign - return 1 if positive, 0 if zero, and -1 if negative
   Examples: sign(130) = 1, sign(-23) = -1
   Legal ops: ! ~ & ^ | + << >>
   Max ops : 10
*/
int sign(int x) {
    int signBit = (!!x) | (x >> 31);
    return signBit;
}
/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 
int bang(int x) {
    return 0;
}
int main(){
    printf("BITAND(6,5) = %d\n",bitAnd(6,5));
    printf("BITXOR(4,5) = %d\n",bitXor(4,5));
    printf("SIGNBIT(-23) = %d\n",sign(-23));
}