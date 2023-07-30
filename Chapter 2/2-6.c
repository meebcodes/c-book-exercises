#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

unsigned int set_bits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);
unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n);

int main(void) {
    unsigned int x = 31;
    unsigned int y = 32;
    unsigned int p = 3;
    unsigned int n = 3;

    printf("\n(Hex representations)\nx: %x, y: %x, p: %x, n: %x", x, y, p, n);

    x = set_bits(x, p, n, y);

    printf("\nAfter set bits: %x\n", x);
    return 0;
}

// assumes p > n
unsigned int set_bits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
    // make y into bitmask containing only the bits we want to set to
    y = get_bits(y, n-1, n) << (p+1-n);

    // make z bitmask for flipping bits we want to set in x to 0
    unsigned int z = ((~0 << n) ^ (~0)) << (p+1-n);

    // flip bits to set to 0
    x = x ^ z;

    // apply y bitmask to get result
    return (x ^ y);
}

unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}