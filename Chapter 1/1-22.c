#include <stdio.h>

/* fold lines at a certain column, preferably at the last blank. 
   this solution still has a few issues...
   but it's mostly functional */

#define MAXLINE 1000
#define COLUMN_STOP 10   // zero-indexed column to stop at

int get_line(char s[], int lim);
void fold_line(char line[], int len);

int main(){
    int len;
    char line[MAXLINE];

    // get lines until we stop receiving input
    while((len = get_line(line, MAXLINE)) > 0){
        // fold the current line
        fold_line(line, len);
    }
}

void fold_line(char line[], int len){
    int first_unprinted = 0;    // index of the first character we haven't printed yet
    int cur_column = 0;         // index of the current column on the line we're printing to

    // iterate through the entire input line
    for(int cur_pos = 0; cur_pos < len; cur_pos++){
        // if we find a space or the end of the input line
        if(line[cur_pos] == ' ' || cur_pos == len - 1){
            // if we can print all the characters up to this point without going beyond our column stop
            if(cur_pos - first_unprinted + cur_column <= COLUMN_STOP){
                // print all those characters
                while(first_unprinted <= cur_pos){
                    putchar(line[first_unprinted]);
                    cur_column++;
                    first_unprinted++;
                }
                // if this puts us at the end of the column or end of the printed line, start a new printed line
                if(cur_column == COLUMN_STOP || cur_pos == len - 1){
                    putchar('\n');
                    cur_column = 0;
                }
            // if we can't print all the characters up to this point without going beyond our column stop
            } else {
                // print chars up to the column on successive print lines until we have no more to print
                while(first_unprinted <= cur_pos){
                    // start new lines until we're done, just don't start the first printed line with a newline
                    if(first_unprinted != 0){
                        putchar('\n');
                        cur_column = 0;
                    }
                    // print all the chars we can on this print line
                    for(int i = cur_column; i <= COLUMN_STOP && first_unprinted <= cur_pos; i++){
                        putchar(line[first_unprinted]);
                        first_unprinted++;
                        cur_column++;
                    }
                }
                // if this is the end of the input line, print a newline as long as we haven't already
                if(cur_pos == len - 1){
                    putchar('\n');
                }
            }
        }
    }
    return;
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