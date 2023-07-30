#include <stdio.h>
#include <ctype.h>

// This doesn't work yet :( fix later

unsigned int rightrot(unsigned int x, unsigned int n);
unsigned int set_bits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);
unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n);

int main(void) {
    unsigned char x = 8;
    printf("\nx: %u", x);
    x = rightrot(x, 2);
    printf("\nx after rightrot x2: %u", x);
    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n){
    if(x == 0 || n == 0)
        return x;

    // find position of leftmost bit
    unsigned int y = x;
    unsigned int left_bit_pos = 0;
    while (y >= 1){
        y >>= 1;
        left_bit_pos++;
    }

    // no need to perform any full cycles
    n %= left_bit_pos;
    if (n == 0)
        return x;
    
    // get the bits that will be rotated out in the necessary position for a bitmask
    unsigned int z = 0;
    printf("\n\tz: %u, lbp: %u, n: %u, x: %u", z, left_bit_pos, n, x);
    z = set_bits(z, left_bit_pos, n, x);
    printf("\n\tz: %u", z);

    // shift and apply the bitmask
    return (z | (x >> n));
}

// assumes p >= n-1
unsigned int set_bits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
    // make y into bitmask containing only the bits we want to set to
    y = get_bits(y, n-1, n) << (p+1-n);
    printf("\n\t\ty: %u", y);

    // make z bitmask for flipping bits we want to set in x to 0
    unsigned int z = ((~0 << n) ^ (~0)) << (p+1-n);
    printf("\n\t\tz: %u", z);

    // flip bits to set to 0
    x = x ^ z;

    // apply y bitmask to get result
    return (x ^ y);
}

unsigned int get_bits(unsigned int x, unsigned int p, unsigned int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}