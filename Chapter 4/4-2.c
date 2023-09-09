#include <ctype.h>
#include <stdio.h>
#include <math.h>

double atof(char s[]);

int main(void){
    double a, b;

    char a_str[50] = "256.256e2";
    char b_str[50] = "-13.082678";

    printf("String a: %s\nString b: %s", a_str, b_str);
    a = atof(a_str);
    b = atof(b_str);

    printf("\n\nDouble a: \n%f\nDouble b: \n%f", a, b);

    return 0;
}

double atof(char s[]){
    double val, power;
    int i, sign, expsign, expval;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e' || s[i] == 'E'){
        i++;

        // check for optional exponent sign
        expsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
    
        // get exponent
        for (expval = 0; isdigit(s[i]); i++) {
            expval = 10 * expval + (s[i] - '0');
        }
        return (sign * val / power) * (expsign * (pow(10, expval)));

    }
    return sign * val / power;
}