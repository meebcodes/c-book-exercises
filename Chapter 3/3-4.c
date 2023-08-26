#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    The book's version of itoa does not handle the largest negative number (-2^(wordsize - 1)) because
    it flips the sign of the integer before converting it to a string. With two's complement, the absolute
    value of the largest negative number will always be one more than the value of the largest positive number
    able to be stored in the given variable. If the largest negative number is supplied to the book's version
    of itoa and is subsequently sign-flipped, it will be read as 0 instead of its positive inverse.
*/

void itoa(int n, char s[]);
void reverse(char str[], int len);

int main(void){
    int a = 256;
    int b = INT_MIN;

    char a_str[50] = "";
    char b_str[50] = "";

    printf("Int a: %d\nInt b: %d", a, b);
    itoa(a, a_str);
    itoa(b, b_str);

    printf("\n\nString a: %s\nString b: %s", a_str, b_str);
    
    return 0;
}

/* itob: convert n to characters in s in base b */
void itoa(int n, char s[]){
    int i, sign;

    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((abs(n /= 10)) > 0);
        
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s, i);
}

/* reverse: reverse a string in place; assume len is accurate */
void reverse(char str[], int len){
    int start = 0;
    int end = len - 1;
    while(end > start){
        // swap start and end chars
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        // step inward from both sides
        ++start;
        --end;
    }
}