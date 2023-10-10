#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main(void){
    int result;
    float a;
    while((result = getfloat(&a)) != EOF){
        if (result != 0)
            printf("\nRetrieved float: %f\n", a);
        else
            // bad input
            return -1;
    }
    return 0;
}

int getfloat(float *pn) {
    int c, sign, place;

    // skip whitespace
    while (isspace(c = getch()))
        ;
    
    // check for digits
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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

    // if we get a decimal point
    if (c == '.'){
        place = 1;
        c = getch();
        // check for trailing digits
        for (; isdigit(c); c = getch())
            *pn = *pn + (float) (c - '0') / (10 * place++) * sign;
    }

    // if we don't get EOF
    if (c != EOF)
        ungetch(c);
    
    return 1;
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