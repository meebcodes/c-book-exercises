#include <stdio.h>
#include <ctype.h>

void squeeze(char s1[], char s2[]);
int c_in_str(char c, char str[]);

int main(void) {
    char s1[] = "hello world!";
    char s2[] = "howdy universe!";

    squeeze(s1, s2);

    printf("%s", s1);
    
    return 0;
}

void squeeze(char s1[], char s2[]){
    int i, j;

    for(i = j = 0; s1[i] != '\0'; i++){
        if(!c_in_str(s1[i], s2))
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int c_in_str(char c, char str[]){
    for(int i = 0; str[i] != '\0'; ++i){
        if(c == str[i])
            return 1;
    }
    return 0;
}