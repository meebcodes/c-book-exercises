#include <ctype.h>
#include <stdio.h>

int getint(int*);
int getch(void);
void ungetch(int);

int main(void){
    int a, result;
    while((result = getint(&a)) != EOF){
        if (result != 0)
            printf("\nRetrieved int: %d\n", a);
        else
            // bad input
            return -1;
    }
    return 0;
}

int getint(int *pn) {
    int c, sign;

    // skip whitespace
    while (isspace(c = getch()))
        ;

    // check for digits
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // not a number
        ungetch(c);
        return 0;
    }

    // check for sign
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();

        // check that we don't just get a sign
        if (!isdigit(c)){
            ungetch(c);
            return 0;
        }
    }
    
    // while we continue to get digits
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    // if we get EOF
    if (c != EOF)
        ungetch(c);
    
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}