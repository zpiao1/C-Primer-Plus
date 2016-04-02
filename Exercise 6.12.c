/* Exercise 6.12.c -- calculates series */
#include <stdio.h>
int main(void)
{
    double x, sum_add, sum_alter, term;
    int n, i;

    printf("Enter number of terms: ");
    while (scanf("%d", &n) == 1)
    {
        sum_add = sum_alter = 0.0;
        term = x = 1.0;
        for (i = 1; i <= n; i++, x += 1.0)
        {
            sum_add += 1.0 / x;
            sum_alter += term / x;
            term *= -1.0;
        }
        printf("The result of the first series is: %g\n", sum_add);
        printf("The result of the second series is: %g\n", sum_alter);
        printf("Enter next number of terms: ");
    }

    return 0;
}
