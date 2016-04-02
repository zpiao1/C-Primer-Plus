/* Exercise 14.1.c -- A structure of months */
#include <stdio.h>
#include <string.h>
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

int daysupto(char * mname);
char * s_gets(char * st, int n);
int main(void)
{
    char month_name[NAMELEN];
    int days;

    puts("Enter the name of the month, end with an empty line:");
    while (s_gets(month_name, NAMELEN) != NULL && month_name[0] != '\0')
    {
        days = daysupto(month_name);
        if (days)
        {
            printf("Total days in the year up to and including ");
            printf("%s is %d\n", month_name, days);
        }
        else
            printf("Your name of month is incorrect!\n");
        puts("Enter the next name of the month:");
    }
    puts("Done!");

    return 0;
}

int daysupto(char * mname)
{
    int i;
    int ret_days = 0;

    for (i = 0; i < MONTHS; i++)
    {
        ret_days += months[i].days;
        if (strcmp(months[i].name, mname) == 0)
            break;
    }

    if (i == MONTHS)
        ret_days = 0;

    return ret_days;
}

char * s_gets(char * st, int n)
{
    char * ret_val, * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
