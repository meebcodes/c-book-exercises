#include <stdio.h>

/*
    Exercise 5-9: Rewrite the routines day_of_year and month_day with pointers instead of indexing.

    Got confused on this one because I assumed that, since a 2D array in C is laid out in contiguous memory,
    I only needed to dereference daytab once after doing the rest of the necessary pointer arithmetic,
    given that daytab = *daytab = daytab[0]. However! Though each of these terms share the same value,
    they are not the same type. daytab is a pointer to a pointer to an int. *daytab is a pointer to an int,
    as is daytab[0]. So we have to dereference daytab as *daytab (or daytab[0]) before doing the subsequent
    pointer arithmetic and then dereferencing it again.

    ...At least, I think so. I get the function, but it's possible I might have some of the theory wrong.
*/

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
    int i, leap;

    leap = year%4 == 0 && year %100 != 0 || year%400 == 0;

    // check for valid month and day value
    if(month < 1 || month > 12 || daytab[leap][month] < day)
        return -1;

    for (i = 1; i < month; i++){
        day += *(*daytab + leap*13 + i);
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    // check for valid yearday value
    if(yearday > (365 + leap) || yearday < 1){
        *pmonth = -1;
        *pday = -1;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *(*daytab + leap*13 + i);
    *pmonth = i;
    *pday = yearday;
}

int main(void) {
    int year = 2000;
    int month = 3;
    int day = 1;
    printf("%d/%d/%d is day %d of year %d.\n", month, day, year, day_of_year(year, month, day), year);

    int year_day = 61;
    month_day(year, year_day, &month, &day);
    printf("Day %d of year %d is %d/%d/%d.", year_day, year, month, day, year);
    return 0;
}