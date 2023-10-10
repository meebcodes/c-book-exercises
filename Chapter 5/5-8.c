#include <stdio.h>

/*
    Exercise 5-8: There is no error checking in day_of_year or month_day. Remedy this defect.

    My solution here is to abort either function early as soon as it determines whether
    an invalid day/month/yearday value has been supplied and return/write 
    values of -1 to indicate an error.

    Not particularly sophisticated, but avoids garbage values and segfaults.
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
        day += daytab[leap][i];
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
        yearday -= daytab[leap][i];
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