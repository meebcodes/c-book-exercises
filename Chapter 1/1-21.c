#include <stdio.h>

/* replace any consecutive blanks with the minimum number of tabs + blanks needed to fill the same space */

#define MAXLINE 1000        // max input line length
#define TABSTOP 4           // line number before tab stop
#define IN_BLANKS 1    // indicates that the last character was a blank
#define IN_WORDS 0     // indicates that the last character was not a blank
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    // while we're still reading input
    while((len = get_line(line, MAXLINE)) > 0){
        int column = 0;
        int spaces = 0;
        int state = IN_WORDS;
        int num_tabs = 0;
        int num_spaces = 0;

        for(int i = 0; i < len; i++){
            // if we are in the middle of a word, continue
            if(state == IN_WORDS && line[i] != ' '){
                putchar(line[i]);
            // if we find a first blank, start keeping track of how many
            } else if(state == IN_WORDS && line[i] == ' '){
                spaces = 1;
                state = IN_BLANKS;
            // if we find more blanks, keep keeping track of how many
            } else if (state == IN_BLANKS && line[i] == ' '){
                spaces += 1;
            // if we find the end of a chain of blanks, replace with tabs + blanks
            } else {
                num_tabs = spaces / TABSTOP;
                num_spaces = spaces % TABSTOP;
                for(int j = 0; j < num_tabs; j++)
                    putchar('\t');
                for(int j = 0; j < num_spaces; j++)
                    putchar(' ');
                spaces = 0;
                state = IN_WORDS;
                putchar(line[i]);
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