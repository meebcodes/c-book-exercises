// Write input one word per line.

#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main(int argc, char* argv[]){
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        putchar(c);
    }
}