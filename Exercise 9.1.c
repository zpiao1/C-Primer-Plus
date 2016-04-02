/* Exercise 9.1.c -- min(x, y) */
#include <stdio.h>
#include <float.h>
double min(double x, double y);
int main(void)
{
    double x, y;

    printf("Enter two double values, q to quit:\n");
    while (scanf("%lf%lf", &x, &y) == 2)
    {
        printf("The min of x and y is: %g.\n", min(x, y));
        printf("Enter two double values, q to quit:\n");
    }

    return 0;
}

double min(double x, double y)
{
    return (x - y > FLT_EPSILON ? y : x);
}
