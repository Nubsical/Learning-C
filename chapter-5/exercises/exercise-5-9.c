#include <stdio.h>

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
    int leap;
    leap = year%4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *i = daytab[leap] + 1;
    while(i < daytab[leap] + month)
        day += *i++;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int leap;
    char *i;
    leap = year%4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = daytab[leap]+1; yearday > *i; i++)
        yearday -= *i;
    *pmonth = i-daytab[leap];
    *pday = yearday;
}

main(){
    int m = 0;
    int d = 0;
    printf("%d\n", day_of_year(2005, 3, 14));
    month_day(2008, 69, &m, &d);
    printf("%d, %d\n", m, d);
}