#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(void) {
    char a[] = "0x10";
    char b[] = "f";
    char c[] = "0XAbcdEF0";
    char d[] = "not_a_hex_string";

    printf("\n%s, %s, %s, %s", a, b, c, d);
    printf("\n%d, %d, %d, %d", htoi(a), htoi(b), htoi(c), htoi(d));
    
    return 0;
}

int htoi(char s[]){
    int i = 0;
    int result = 0;

    // skip hex prefix
    if(s[i] != '\0' && s[i] == '0')
        if(s[1] != '\0' && (s[i+1] == 'x' || s[i+1] == 'X'))
            i = 2;

    for(i; s[i] != '\0'; ++i){
        // convert all letters to uppercase
        if((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')){
            char c = toupper(s[i]);
            // increase running sum by a power of 16, add this hex char's value
            result = result * 16 + (c - 'A' + 10);
        } else if (s[i] >= '0' && s[i] <= '9') {
            // increase running sum by a power of 16, add this digit
            result = result * 16 + (s[i] - '0');
        } else {
            // invalid hex string
            return -1;
        }
    }
    return result;
}