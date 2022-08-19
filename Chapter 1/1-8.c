// Count number of newlines, tabs, and spaces.

#include <stdio.h>

int main(int argc, char* argv[]){
    int c, nl, nt, ns;

    nl = 0;
    nt = 0;
    ns = 0;
    
    while((c = getchar()) != EOF){
        if(c == '\n')
            ++nl;
        else if(c == '\t')
            ++nt;
        else if(c == ' ')
            ++ns;
    }

    printf("Newlines: %d\tTabs: %d\tSpaces: %d\n", nl, nt, ns);

    return 0;
}