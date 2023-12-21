#include <stdio.h>
#include <assert.h>
/* bitAnd - x & y using only ~ and |
   Example bitAnd(6, 5) = 4
   Legal ops:  ~ |
   Max ops: 8
*/
int bitAnd(int x, int y)
{
    int bitsAnd = ~(~x | ~y);
    return bitsAnd;
}
/* bitXor - x ^ y using only ~ and &
   Example bitXor(4, 5) = 1
   Legal ops:  ~ &
   Max ops: 14
*/
int bitXor(int x, int y)
{
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
int sign(int x)
{
    int signBit = (!!x) | (x >> 31);
    return signBit;
}
/* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/
int getByte(int x, int n) {
    int getbyte = (x >> (n << 3)) & 0xff;
    return getbyte;
}
/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/
int logicalShift(int x, int n) {
    return ((x >> n) & ~(((1 << 31) >> n) << 1));
}
/* bang - Compute !x without using !
 *  Examples: bang(3)=0, bang(0)=1
 *  Legal ops: ~ & ^ | + << >>
 *  Max ops: 12
 */
int bang(int x)
{
    return 0;
}
int main()
{
    assert(bitAnd(6, 5) == 4);
    assert(bitXor(4, 5) == 1);
    assert(sign(-23) == -1);
    assert(getByte(0x12345678,1) == 0x56);
    assert(logicalShift(0x87654321, 4) == 0x8765432);
    printf("Test Cases running Successfully");
}