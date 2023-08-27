#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char str[], int len);

int main(void){
    int a = 124789;
    int b = INT_MIN;

    char a_str[50] = "";
    char b_str[50] = "";

    printf("Int a: %d\nInt b: %d", a, b);
    itob(a, a_str, 2);
    itob(b, b_str, 16);

    printf("\n\nString a: %s\nString b: %s", a_str, b_str);
    
    return 0;
}

/* itob: convert n to characters in s in base b */
// +=7
void itob(int n, char s[], int b){
    int i, sign, digit;

    sign = n;

    i = 0;
    do {
        digit = abs(n % b);
        // account for alphabetic digits in +base 10
        if(digit > 9)
            s[i++] = abs(n % b) + '0' + 7;
        else
            s[i++] = abs(n % b) + '0';
    } while ((abs(n /= b)) > 0);
        
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