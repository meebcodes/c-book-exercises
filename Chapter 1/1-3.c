#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20 /* step size */

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300 */

int main() {

    int fahr;
    float celsius;

    printf("FAHRENHEIT\tCELSIUS\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        // calculate Celsius conversion
        celsius = (5.0 / 9.0) * (fahr - 32);
        // print table
        printf("   %3d\t\t%6.1f\n", fahr, celsius);
    }
}