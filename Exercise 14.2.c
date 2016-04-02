/* Exercise 14.2.c -- Shows the number of days up to the given
   day */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MONTHS 12
#define NAMELEN 10
typedef struct month_info {
    char name[NAMELEN];
    char abbr[4];
    int days;
    int month_num;
} MONTH_INFO;

MONTH_INFO months[MONTHS] =
{
    {"January",   "Jan", 31,  1},
    {"February",  "Feb", 28,  2},
    {"March",     "Mar", 31,  3},
    {"April",     "Apr", 30,  4},
    {"May",       "May", 31,  5},
    {"June",      "Jun", 30,  6},
    {"July",      "Jul", 31,  7},
    {"August",    "Aug", 31,  8},
    {"September", "Sep", 30,  9},
    {"October",   "Oct", 31, 10},
    {"November",  "Nov", 30, 11},
    {"December",  "Dec", 31, 12},
};

void check_leap_year(int year);
int days_up_to(int year, int month, int day);
int get_month(char * month_str);
char * s_gets(char * st, int n);
void eatline(void);
int main(void)
{
    int year, day, month;
    char monthin[NAMELEN];

    puts("Enter the day:");
    scanf("%d", &day);
    eatline();
    printf("Enter the month by the name, the number, or the");
    printf("abbreviation:\n");
    s_gets(monthin, NAMELEN);
    month = get_month(monthin);
    puts("Enter the year:");
    scanf("%d", &year);

    printf("Days in %d up to %s %d total %d.\n", year,
           months[month - 1].name, day,
           days_up_to(year, month, day));

    return 0;
}

void check_leap_year(int year)
{
    if (year % 400 == 0)
        months[1].days = 29;
    else if (year % 4 == 0 && year % 100 != 0)
        months[1].days = 29;
}

int days_up_to(int year, int month, int day)
{
    int i;
    int total_days = 0;
    check_leap_year(year);
    for (i = 0; i < month; i++)
    {
        if (i == month - 1)
            if (day > months[i].days)
            {
                fprintf(stderr, "Wrong day!\n");
                exit(EXIT_FAILURE);
            }
            else
                total_days += day;
        else
            total_days += months[i].days;
    }

    return total_days;
}

int get_month(char * month_str)
{
    int i;
    char temp[3];
    for (i = 0; i < MONTHS; i++)
    {
        sprintf(temp, "%d", months[i].month_num);
        if (strcmp(month_str, months[i].abbr) == 0)
            return (i + 1);
        else if (strcmp(month_str, months[i].name) == 0)
            return (i + 1);
        else if (strcmp(month_str, temp) == 0)
            return (i + 1);
    }
    fprintf(stderr, "Wrong month!\n");
    exit(EXIT_FAILURE);
}

char * s_gets(char * st, int n)
{
    char * ret_str, * find;
    ret_str = fgets(st, n, stdin);
    if (ret_str)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            eatline();
    }

    return ret_str;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
