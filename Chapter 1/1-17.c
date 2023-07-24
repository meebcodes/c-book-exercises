#include <stdio.h>

/* echo any lines of input longer than a certain character limit */

#define PRINT_LEN 20

int main(){
    int c, state;
    c = state = 0;
    int temp[PRINT_LEN];

    for(int len = 1; (c = getchar()) != EOF; ++len){
        // if we've hit our print length
        if (len == PRINT_LEN + 1){
            // print every character we've saved so far
            for(int i = 0; i < PRINT_LEN; i++)
                putchar(temp[i]);
            putchar(c);
        // if we've already surpassed our print length
        } else if (len > PRINT_LEN) {
            putchar(c);
            // if we've hit a newline, stop printing
            if (c == '\n') {
                len = 0;
            }
        // if we hit a newline, reset length
        } else if (c == '\n'){
            len = 0;
        // if we haven't surpassed our print length yet
        } else {
            temp[len - 1] = c;
        }
    }
    return 0;
}