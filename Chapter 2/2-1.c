#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <math.h>

#define U_MIN 0
#define C_W 40

/* does not yet include limit computations for float + double. */

void print_limits_by_constant(void);
void print_limits_by_computation(void);

int main(void) {

    print_limits_by_constant();
    print_limits_by_computation();

    return 0;
}

void print_limits_by_constant(void){
    printf("\n\nType limits by constants in limits.h and float.h:\n");
    printf("\nTYPE\t\tMIN\t\t\t\t\t MAX\n");

    // chars
    printf("\ndefault char\t%-35d %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char\t%-35u %d\n", U_MIN, UCHAR_MAX);
    printf("signed char\t%-35d %d\n", SCHAR_MIN, SCHAR_MAX);

    // shorts
    printf("\nunsigned short\t%-35u %u\n", U_MIN, USHRT_MAX);
    printf("signed short\t%-35d %d\n", SHRT_MIN, SHRT_MAX);
    
    // ints
    printf("\nunsigned int\t%-35u %u\n", U_MIN, UINT_MAX);
    printf("signed int\t%-35d %d\n", INT_MIN, INT_MAX);

    // longs
    printf("\nunsigned long\t%-35u %lu\n", U_MIN, ULONG_MAX);
    printf("signed long\t%-35ld %ld\n", LONG_MIN, LONG_MAX);

    // floats
    printf("\nfloat\t\t%-35g %g\n", FLT_MIN, FLT_MAX);

    // doubles
    printf("\ndouble\t\t%-35g %g\n", DBL_MIN, DBL_MAX);

    // long doubles
    printf("\ndouble\t\t%-35Lg %Lg\n", LDBL_MIN, LDBL_MAX);
}

void print_limits_by_computation(void){

    printf("\n\nType limits by computation:\n");
    printf("\nTYPE\t\tMIN\t\t\t\t\t MAX\n");

    unsigned long max = 0;
    signed long min = 0;

    // -----
    // chars
    // -----

    // unsigned char
    for(unsigned char c = max = 1; c >= 1; c *= 2)
        max = c;
    printf("\nunsigned char\t%-35d %lu\n", U_MIN, (max - 1) + max);

    // signed char
    for(signed char c = max = 1; c >= 1; c *= 2)
        max = c;
    for(signed char c = min = -1; c <= -1; c *=2)
        min = c;
    printf("unsigned char\t%-35ld %ld\n", min, (max - 1) + max);

    // -----
    // shorts
    // -----
    
    // unsigned short
    for(unsigned short s = max = 1; s >= 1; s *= 2)
        max = s;
    printf("\nunsigned short\t%-35d %lu\n", U_MIN, (max - 1) + max);

    // signed short
    for(signed short s = max = 1; s >= 1; s *= 2)
        max = s;
    for(signed short s = min = -1; s <= -1; s *=2)
        min = s;
    printf("signed short\t%-35ld %ld\n", min, (max - 1) + max);

    // -----
    // ints
    // -----

    // unsigned int
    for(unsigned int i = max = 1; i >= 1; i *= 2)
        max = i;
    printf("\nunsigned int\t%-35d %lu\n", U_MIN, (max - 1) + max);

    // signed int
    for(signed int i = max = 1; i >= 1; i *= 2)
        max = i;
    for(signed int i = min = -1; i <= -1; i *=2)
        min = i;
    printf("signed int\t%-35ld %ld\n", min, (max - 1) + max);

    // -----
    // longs
    // -----

    // unsigned long
    for(unsigned long l = max = 1; l >= 1; l *= 2)
        max = l;
    printf("\nunsigned long\t%-35d %lu\n", U_MIN, (max - 1) + max);

    // signed int
    for(signed long l = max = 1; l >= 1; l *= 2)
        max = l;
    for(signed long l = min = -1; l <= -1; l *=2)
        min = l;
    printf("signed long\t%-35ld %ld\n", min, (max - 1) + max);

}