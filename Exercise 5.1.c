/* Exercise 5.1.c -- converts minutes to hours and minutes */
#include <stdio.h>
int main(void)
{
    int time, min, hour;
    const int MIN_PER_HOUR = 60;
    printf("Enter the time in minutes: ");
    scanf("%d", &time);
    while (time > 0)
    {
        hour = time / MIN_PER_HOUR;
        min = time % MIN_PER_HOUR;
        printf("%d minutes = %d hours %d minutes\n", time, hour, min);
        printf("Enter the time in minutes: ");
        scanf("%d", &time);
    }

    return 0;
}
