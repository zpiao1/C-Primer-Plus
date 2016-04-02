/* Exercise 16.4.c -- measure time elapsed in C */
#include <stdio.h>
#include <time.h>
void loop_time(double delay);

int main(void)
{
    double delay;
    printf("Enter a time delay in seconds: ");
    scanf("%lf", &delay);
    loop_time(delay);

    return 0;
}

void loop_time(double delay)
{
    int i = 0;
    double t1 = ((double)clock() / CLOCKS_PER_SEC);
    double t2;

    do
    {
        i++;
        t2 = ((double)clock() / CLOCKS_PER_SEC);
    } while (t2 - t1 < delay);

    printf("%d loops have been executed.\n", i);
}
