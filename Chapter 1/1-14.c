// Print a histogram of the frequency of alphabetic characters.

#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main(int argc, char* argv[]){
    int c;
    int hist[26];

    for(int i = 0; i < 26; ++i){
        hist[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c >= 'A' && c <= 'Z'){
            hist[c - 'A'] += 1;
        } else if (c >= 'a' && c <= 'z'){
            hist[c - 'a'] += 1;
        }
    }

    printf("Histogram of frequency of alphabetic characters:\n");
    for(int i = 0; i < 26; ++i){
        printf("\n%c:\t", ('a' + i));
        for(int j = 0; j < hist[i]; ++j){
            putchar('=');
        }
    }
    putchar('\n');
}