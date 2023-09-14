#include <stdio.h>

void itoa(int n, char a[]);
void itoa_helper(int n, char a[]);

int main(void){

    int a = -256;
    char s[100] = "";

    printf("\nInteger: %d", a);
    itoa(a, s);
    printf("\nString: %s", s);

    return 0;
}

int i;

void itoa(int n, char s[]){
    i = 0;
    if (n < 0){
        s[i++] = '-';
        n = -n;
    }
    itoa_helper(n, s);
    s[++i] = '\0';
}

void itoa_helper(int n, char s[]){
    if (n / 10){
        itoa_helper(n / 10, s);
    }
    s[i++] = (n % 10 + '0');
}