#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void itoa(int n, char s[], int min_width);
void reverse(char str[], int len);

int main(void){
    int a = 256;
    int b = INT_MIN;

    char a_str[50] = "";
    char b_str[50] = "";

    printf("Int a: %d\nInt b: %d", a, b);
    itoa(a, a_str, 20);
    itoa(b, b_str, 20);

    printf("\n\nString a: \n%s\nString b: \n%s", a_str, b_str);
    
    return 0;
}

/* itob: convert n to characters in s in base b */
void itoa(int n, char s[], int min_width){
    int i, sign;

    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((abs(n /= 10)) > 0);
        
    if (sign < 0)
        s[i++] = '-';

    if(i < min_width){
        do {
            s[i++] = ' ';
        } while (i < min_width);
    }

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