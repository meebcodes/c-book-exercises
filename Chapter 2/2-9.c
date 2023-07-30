#include <stdio.h>

int bitcount(unsigned x);

/*
    x &= (x-1) deletes the rightmost 1-bit in x.

    This is because x-1 is equal to x where all of the bits including and to the right of
    the rightmost 1-bit have been flipped.

    ex:
        16 = 000[1 0000]
        15 = 000[0 1111]

        22 = 0001 01[10]
        21 = 0001 01[01]

        9 = 0000 100[1]
        8 = 0000 100[0]

    As can be seen in any of the above examples, if we were to perform a bitwise AND 
    on x and (x-1), we would effectively flip to zero all of the bits including 
    and to the right of the rightmost 1-bit.

    ex:
                 v
        16  = 0001 0000
        15  = 0000 1111
        &   = 0000 0000
                 ^
                     v
        22  = 0001 0110
        21  = 0001 0101
        &   = 0001 0100
                     ^
*/

int main(void) {
    unsigned int x = 255;
    unsigned int y = 16;
    unsigned int z = 9;

    printf("x: %u, bitcount: %d\n", x, bitcount(x));
    printf("y: %u, bitcount: %d\n", y, bitcount(y));
    printf("z: %u, bitcount: %d\n", z, bitcount(z));

    return 0;
}

int bitcount(unsigned int x){
    int b;

    for(b = 0; x >= 1; x &= (x-1))
        b++;
    return b;
}