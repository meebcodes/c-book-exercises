#include <stdio.h>

#define swap(t, x, y) \
    t TEMP ## x ## y = x; \
    x = y; \
    y = TEMP ## x ## y;

int main(void){
    int a, b;
    a = 200;
    b = 400;

    printf("\nOriginal: int a = %d, int b = %d", a, b);
    swap(int, a, b);
    printf("\nSwapped: int a = %d, int b = %d", a, b);

    float c, d;
    c = 12.345;
    d = -54.321;

    printf("\nOriginal: float c = %f, float d = %f", c, d);
    swap(float, c, d);
    printf("\nSwapped: float c = %f, float d = %f", c, d);

    char e, f;
    e = 'e';
    f = 'f';

    printf("\nOriginal: char e = %c, char f = %c", e, f);
    swap(char, e, f);
    printf("\nSwapped: char e = %c, char f = %c", e, f);

    return 0;
}