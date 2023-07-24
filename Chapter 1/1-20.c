#include <stdio.h>

/* replace any tab chars with a number of spaces until the next tab stop */

#define MAXLINE 1000    // max input line length
#define TABSTOP 4       // line number before tab stop

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    // while we're still reading input
    while((len = get_line(line, MAXLINE)) > 0){
        int column = 0;
        for(int i = 0; i < len; i++){
            // if we find a tab, replace it with spaces until the next tabstop
            if (line[i] == '\t'){
                for(int j = column; j < TABSTOP; j++)
                    putchar(' ');
                column = 0;
            // if we find any other char, echo it and increment the column counter
            } else {
                putchar(line[i]);
                column = (column + 1) % 4;
            }
        }
        printf("\n");
    }
    return 0;
}

/* getline: read a line into s, return its length */
int get_line(char s[], int lim){
    int c, i;

    // getchar up until 1 before limit (allowing for null char terminator);
    // break if we get EOF or newline
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    // if this line has ended
    if (c == '\n'){
        // terminate string
        s[i] = '\0';
    // if we've hit our storage limit
    } else if (i == lim-1){
        // terminate string, but keep incrementing length
        s[i] = '\0';
        while(c != EOF && c != '\n'){
            c = getchar();
            ++i;
        }
    } else if (c == EOF){
        return 0;
    }
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}