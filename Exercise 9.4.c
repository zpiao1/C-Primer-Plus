/* Exercise 9.4.c -- Harmonic mean */
#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
double harmonic_mean(double x, double y);
bool checkZero(double x, double y);
int main(void)
{
    double a, b;
    printf("Enter two double numbers, otherwise quitting the program.\n");
    while (scanf("%lf%lf", &a, &b) == 2)
    {
        if (checkZero(a, b))
        {
            printf("Please enter nonzero values.\n");
            continue;
        }
        printf("The harmonic mean of a and b is: %f\n", harmonic_mean(a, b));
        printf("Enter two double numbers, otherwise quitting the program.\n");
    }

    return 0;
}

double harmonic_mean(double x, double y)
{
    return 2 / (1 / x + 1 / y);
}

bool checkZero(double x, double y)
{
    return (fabs(x * y) <= DBL_EPSILON);
}
