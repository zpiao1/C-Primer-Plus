/* Exercise 6.10.c -- calculate sum of squares from one end to the other */
#include <stdio.h>
int main(void)
{
    int upper, lower, count, sum;

    printf("Enter lowerand upper limits: ");
    scanf("%d%d", &lower, &upper);

    do
    {
        sum = 0;
        for (count = lower; count <= upper; count++)
            sum += count * count;
        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter the next set of limits: ");
        scanf("%d%d", &lower, &upper);
    } while (lower < upper);
    printf("Done\n");

    return 0;
}
