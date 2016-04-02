/* Exercise 4.5.c -- prints the speed of downloading a file */
#include <stdio.h>
int main(void)
{
    float speed, size, time;
    printf("Enter the download speed in Mbs: ");
    scanf("%f", &speed);
    printf("Enter the size of a file in MB: ");
    scanf("%f", &size);
    time = size / speed * 8.0;
    printf("At %.2f megabits per second,", speed);
    printf("a file of %.2f megabytes\n", size);
    printf("downloads in %.2f seconds.\n", time);

    return 0;
}
