/* Exercise 12.4.c -- returns the number that the function
   is called */
#include <stdio.h>
int show_times(void);
int main(void)
{
    const int times = 10;
    int i, call_times;

    for (i = 0; i < times; i++)
        call_times = show_times();
    printf("The function is called %d times\n", call_times);
    return 0;
}

int show_times(void)
{
    static int count = 1;
    return count++;
}
