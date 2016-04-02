/* Exercise 6.14.c -- uses array to store doubles and the cumulative sums */
#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    double nums[SIZE], sums[SIZE];
    int i;

    printf("Enter 8 double numbers: \n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%lf", &nums[i]);
    }

    sums[0] = nums[0];
    for (i = 1; i < SIZE; i++)
    {
        sums[i] = sums[i - 1] + nums[i];
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("%-8.3f", nums[i]);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%-8.3f", sums[i]);
    }

    return 0;
}
