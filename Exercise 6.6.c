/* Exercise 6.6.c -- prints integer, squares and cubes in a table */
#include <stdio.h>
int main(void)
{
    int lower_limit, upper_limit, count;

    printf("Enter the lower limit for the table: ");
    scanf("%d", &lower_limit);
    printf("Enter the upper limit for the table: ");
    scanf("%d", &upper_limit);
    printf("  n   n^2  n^3  \n");
    printf("----------------\n");
    for (count = lower_limit; count <= upper_limit; count++)
        printf("%-5d%-5d%-5d\n", count, count * count, count * count * count);

    return 0;
}
