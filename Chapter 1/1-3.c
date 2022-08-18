// Fahrenheit to Celsius table with header.

#include <stdio.h>

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
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    }
}