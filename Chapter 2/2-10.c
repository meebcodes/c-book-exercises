#include <stdio.h>

int lower(int c);

int main(void) {
    char* str = "HELLO WORLD! (hello world!!)";
    int c;

    for(int i = 0; str[i] != '\0'; i++){
        putchar(lower(str[i]));
    }
    putchar('\n');

    return 0;
}

int lower(int c){
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}