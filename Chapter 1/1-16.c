#include <stdio.h>

/* print the longest line of input (up to max str length) and its actual length */

#define MAXLINE 10    // max input line length

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;                // current line length
    int max;                // maximum line length seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved so far

    max = 0;
    // while we're still reading input
    while((len = get_line(line, MAXLINE)) > 0)
        // check whether this is the longest line, save it and its length if so
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    // if any lines were entered
        printf("Longest line: %s\nActual length: %d", longest, max);
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