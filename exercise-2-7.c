#include <stdio.h>

/* Write a function invert(x,p,n) that returns x
 * with the n bits that begin at position p
 * inverted, leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned val = invert(077,3,2);
    printf("%u\n", val);

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    /* - isolate the n bits that begin at position p
     * - invert those bits
     * - turn off the original n bits from x
     * - OR the replacement bits in? */
    
    unsigned i;

    i = (x >> (p + 1 - n)) & ~(~0 << n); // Isolate the n bits
//    printf("%u, ", i);
    i = ~i & ~(~0 << n); // Invert the n bits
//    printf("%u, ", i);
    i = i << (p + 1 - n); // Move the bits back over to the proper position
//    printf("%u, ", i);
    x = x & ((~0 << (n + p - 1)) | ~(~0 << n)); // turn off the original n bits
//    printf("%u\n", x);
    x = x | i; 

    return x;
}
