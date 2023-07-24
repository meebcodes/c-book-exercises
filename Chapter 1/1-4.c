#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20 /* step size */

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300 */

int main() {

    int celsius;
    float fahr;

    printf(" CELSIUS\tFAHRENHEIT\n");

    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        // calculate Celsius conversion
        fahr = (9.0 / 5.0) * celsius + 32;
        // print table
        printf("   %3d\t\t%6.1f\n", celsius, fahr);
    }
}