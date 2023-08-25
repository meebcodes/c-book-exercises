#include <stdio.h>

void escape_to_chars(char s[], char t[]);
void chars_to_escape(char s[], char t[]);

int main(void) {
    char s[100] = "\"Hello there! How\tis it going\ntoday?\"\n\'Hello, it's going well.\'";
    char t[200];
    escape_to_chars(s, t);
    printf("[ORIGINAL]: %s\n[ESCAPE_TO_CHARS]: %s\n\n", s, t);
    chars_to_escape(t, s);
    printf("[ESCAPE_TO_CHARS]: %s\n[CHARS_TO_ESCAPE]: %s\n", t, s);

    return 0;
}

void escape_to_chars(char s[], char t[]){
    int c;
    int j = 0;

    // iterate over source string
    for(int i = 0; (c = s[i]) != '\0'; i++){
        // replace any escape sequences with the actual chars 
        // for that escape sequence in the target string
        switch (c){
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\'':
                t[j++] = '\\';
                t[j++] = '\'';
                break;
            case '\"':
                t[j++] = '\\';
                t[j++] = '\"';
                break;
            default:
                t[j++] = c;
                break;
        }
    }
    t[j] = '\0';
    return;
}

void chars_to_escape(char s[], char t[]){
    int c;
    int j = 0;

    // iterate over source string
    for(int i = 0; (c = s[i]) != '\0'; i++){
        // replace any escaped escape sequences with
        // the actual escape sequence in the target string
        switch(c){
            case '\\':
                switch(c = s[++i]){
                    case 'n':
                        t[j++] = '\n';
                        break;
                    case 't':
                        t[j++] = '\t';
                        break;
                    case '\'':
                        t[j++] = '\'';
                        break;
                    case '\"':
                        t[j++] = '\"';
                        break;
                    default:
                        t[j++] = '\\';
                        t[j++] = c;
                        break;
                }
                break;
            default:
                t[j++] = c;
                break;
        }
    }
    t[j] = '\0';
    return;
}