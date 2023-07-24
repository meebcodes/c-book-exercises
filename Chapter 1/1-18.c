#include <stdio.h>

/* echo input, removing any trailing whitespace */

#define MAXLINE 1000    // max input line length

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    // while we're still reading input
    while((len = get_line(line, MAXLINE)) > 0){
        // start at last non-null char
        int end = len - 2;
        // go backward until we hit a non-blank char
        while(end > 0 && (line[end] == ' ' || line[end] == '\t')){
            --end;
        }
        // cut off any trailing blanks or tabs and print
        line[end + 1] = '\0';
        printf("Output: '%s'\n", line);
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