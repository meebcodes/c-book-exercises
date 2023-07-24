#include <stdio.h>

/* removes all comments from a properly-formatted C program file. */

/* 
   Some of this code could easily be condensed, but the simplest solutions
   I could think of off the top of my head involved pointers or strings...
   ... which we haven't reached yet at this point in the book :)
*/

int main(){

    // here is a single line comment.

    int cur_c = 0;
    int prev_c = 0;
    int next_c = 0;

    /* Here is a 
    multi-line
    block comment! */

    /* In multi-line block comments,
    we won't break at / just any // forward slash. */

    int example = 10 / 2;       // this is to show that division signs won't be removed
    printf("Hello // there! Ignore this line.\n\n-----\n\n");   // this is to show that comments in quotations won't be removed

    while ((cur_c = getchar()) != EOF){

        // if we're in a quote, ignore until we see a closing quote
        if(cur_c == '"'){
            while((cur_c = getchar()) != '"' && cur_c != EOF)
                putchar(cur_c);
            if(cur_c == EOF)
                break;
            putchar(cur_c);
            prev_c = cur_c;

        } else if(cur_c == '\''){
            while((cur_c = getchar()) != '\'' && cur_c != EOF)
                putchar(cur_c);
            if(cur_c == EOF)
                break;
            putchar(cur_c);
            prev_c = cur_c;
        }
        
        // if we're not in a quote and we see a forward slash
        if (cur_c == '/'){
            
            // single line comment
            if ((next_c = getchar()) == '/'){
                while((cur_c = getchar()) != '\n' && cur_c != EOF)
                    ;
                if(cur_c == EOF)
                    break;
                putchar(cur_c);
                prev_c = cur_c;

            // block comment
            } else if(next_c == '*'){
                while((cur_c = getchar()) != EOF){
                    if (cur_c == '*'){
                        if((next_c = getchar()) == '/'){
                            cur_c = next_c;
                            break;
                        }
                    }
                }
                if(cur_c == EOF)
                    break;
                prev_c = cur_c;
            
            // not a comment
            } else {
                putchar(cur_c);
                if (next_c == EOF)
                    break;
                prev_c = next_c;
            }

        } else {
            putchar(cur_c);
            prev_c = cur_c;
        }
    }

    return 0;
}