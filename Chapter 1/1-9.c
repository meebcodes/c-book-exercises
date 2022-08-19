// Replace multiple spaces with one space.

#include <stdio.h>

int main(int argc, char* argv[]){
    int lc, c;

    // arbitrary last character to start with
    lc = '\n';

    while((c = getchar()) != EOF){
        if(lc == ' ') {
            if(c != ' ')
                putchar(c);
        }
        else {
            putchar(c);
        }
        lc = c;
    }
    return 0;
}