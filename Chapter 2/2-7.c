#include <stdio.h>
#include <ctype.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);
unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n);

int main(void) {
    unsigned int x = 255;
    unsigned int p = 7;
    unsigned int n = 4;

    printf("\n(Hex representations)\nx: %x, p: %x, n: %x", x, p, n);
    x = invert(x, p, n);
    printf("\nInverted: %x", x);

    return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n){
    
    // make bitmask for inverting specified bits in x
    unsigned int z = ((~0 << n) ^ (~0)) << (p+1-n);

    // xor with x
    return (x ^ z);
}

unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}