#include <stdio.h>
#include <ctype.h>

int c_in_str(char c, char str[]);
int any(char s1[], char s2[]);

int main(void) {
    char s1[] = "hi there!";
    char s2[] = "bonjour tout le monde!";

    printf("\n%s\n%s\n%d", s1, s2, any(s1, s2));

    char s3[] = "a new and interesting sentence";
    char s4[] = "xyz";

    printf("\n%s\n%s\n%d", s3, s4, any(s3, s4));
    
    return 0;
}

int any(char s1[], char s2[]){
    int i;
    for(i = 0; s2[i] != '\0'; i++){
        if (c_in_str(s2[i], s1))
            return i;
    }
    return -1;
}

int c_in_str(char c, char str[]){
    for(int i = 0; str[i] != '\0'; ++i){
        if(c == str[i])
            return 1;
    }
    return 0;
}