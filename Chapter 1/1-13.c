// Print a histogram of the length of words in input.

#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main(int argc, char* argv[]){
    int c, nc, state;
    int hist[10];

    for(int i = 0; i < 10; ++i){
        hist[i] = 0;
    }

    state = OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(nc > 0){
                if(nc >= 10){
                    hist[9] += 1;
                } else {
                    hist[nc - 1] += 1;
                }
                nc = 0;
            }
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
            }
            nc += 1;
        }
    }

    printf("Histogram of character count per word:\n");
    for(int i = 0; i < 10; ++i){
        if(i == 9){
            printf("10+:\t");
        } else {
            printf("%d:\t", i+1);
        }
        for(int j = 0; j < hist[i]; j++){
            putchar('=');
        }
        putchar('\n');
    }
}