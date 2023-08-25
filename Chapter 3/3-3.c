#include <stdio.h>
#include <ctype.h>

// this is still buggy
// ...fix later

void expand(char s1[], char s2[]);

int main(void){
    char s1[100] = "Hello! Please print a-c, b-i, and 3-8! :)";
    char s2[200] = "";

    char s3[100] = "Please also print a-b-c, a-z0-9, and -a-z. :)-";
    char s4[200] = "";
    
    expand(s1, s2);
    expand(s3, s4);

    printf("Original string: %s\n", s1);
    printf("Expanded string: %s\n\n", s2);

    printf("Original string: %s\n", s3);
    printf("Expanded string: %s\n", s4);

    return 0;
}

// assumes that s1 is at least 2 chars in length, and that
// s2 has the space to fit the expanded s1
void expand(char s1[], char s2[]){
    // s2 writing index
    int i = 0;
    // s1 parsing indices (prev, current, next)
    int p = 0;
    int c = 1;
    int n = 2;

    while(s1[c] != '\0'){
        if(s1[c] == '-'){
            // if prev and next chars are letters & next follows prev alphabetically
            if(isalpha(s1[p]) && isalpha(s1[n]) && (tolower(s1[p]) < tolower(s1[n]))){
                // print all letters in sequence
                for(char c = s1[p]; c <= s1[n]; c++){
                    s2[i++] = c;
                }
                // move window 3 steps total
                p += 2, c += 2, n += 2;

                // if our window reaches the end of the string,
                // print any remaining chars and exit
                if(s1[p] == '\0' || s1[c] == '\0' || s1[n] == '\0'){
                    // print p (and c) if needed
                    if(s1[p] != '\0'){
                        s2[i++] = s1[p];
                        if(s1[c] != '\0')
                            s2[i++] = s1[c];
                    }
                    s2[i] = '\0';
                    return;
                }
                continue;
    
            }
            // if prev and next chars are digits 0-9 & next > prev
            if(isdigit(s1[p]) && isdigit(s1[n]) && (s1[p] < s1[n])){
                // print all digits in sequence
                for(char c = s1[p]; c <= s1[n]; c++){
                    s2[i++] = c;
                }
                // move window 3 steps
                p += 3, c += 3, n += 3;
                // if our window reaches the end of the string,
                // print any remaining chars and exit
                if(s1[p] == '\0' || s1[c] == '\0' || s1[n] == '\0'){
                    // print p (and c) if needed
                    if(s1[p] != '\0'){
                        s2[i++] = s1[p];
                        if(s1[c] != '\0')
                            s2[i++] = s1[c];
                    }
                    s2[i] = '\0';
                    return;
                }
                continue;
            }
        } else {
            // this window isn't shorthand, so print prev
            s2[i++] = s1[p];
        }
        // move our s1 parsing window forward a step
        p++, c++, n++;
    }
    // print any remaining chars
    if(s1[p] != '\0'){
        s2[i++] = s1[p];
    }

    // terminate s2
    s2[i] = '\0';

    return;
}