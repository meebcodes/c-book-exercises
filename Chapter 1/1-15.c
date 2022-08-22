// Fahrenheit to Celsius table using a function for conversion.

#include <stdio.h>

float f_to_c(float fahr);

int main(int argc, char* argv[]){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // lower limit of temp table
    upper = 300;    // upper limit of temp table
    step = 20;      // step size

    // print header
    printf("------------------------\n");
    printf("Farenheit\tCelsius\n");
    printf("------------------------\n");
    
    // print table
    for(fahr = lower; fahr <= upper; fahr += step){
        celsius = f_to_c(fahr);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    }
}

float f_to_c(float fahr){
    return (5.0/9.0) * (fahr - 32.0);
}