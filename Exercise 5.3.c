/* Exercise 5.3.c -- converts days to weeks and days */
#include <stdio.h>
int main(void)
{
    int time, day, week;
    const int DAY_PER_WEEK = 7;
    printf("Enter the time in days: ");
    scanf("%d", &time);
    while (time > 0)
    {
        week = time / DAY_PER_WEEK;
        day = time % DAY_PER_WEEK;
        printf("%d days are %d weeks, %d days.\n", time, week, day);
        printf("Enter the time in days: ");
        scanf("%d", &time);
    }

    return 0;
}

