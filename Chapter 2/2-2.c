#include <stdio.h>

int main(void) {
    int lim = 100;
    int i, c;
    char s[lim];

    /* original loop
    for(i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    */


    // rewritten equivalent loop without && or ||
    for(i = 0; i<lim-1; ++i){
        c = getchar();
        if(c == '\n')
            break;
        else if(c == EOF)
            break;
        else
            s[i] = c;
    }
    
    s[i+1] = '\0';

    printf("\n%s", s);
}