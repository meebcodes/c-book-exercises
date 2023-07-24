#include <stdio.h>

/* reverse input strings */

#define MAXLINE 1000    // max input line length

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char str[], int len);

/* print longest input line */
int main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    // while we're still reading input
    while((len = get_line(line, MAXLINE)) > 0){
        // reverse the input
        reverse(line, len);
        printf("%s\n", line);
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

/* reverse: reverse a string in place; assume len is accurate */
void reverse(char str[], int len){
    int start = 0;
    int end = len - 1;
    while(end > start){
        // swap start and end chars
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        // step inward from both sides
        ++start;
        --end;
    }
}