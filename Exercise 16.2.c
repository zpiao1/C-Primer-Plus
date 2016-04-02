/* Exercise 16.2.c -- harmonic mean macro */
#include <stdio.h>
#define HAR_MEAN(X, Y) 2.0 / ((1.0 / (X) + 1.0 / (Y)))

int main(void)
{
    double x, y;
    printf("Enter x and y: ");
    scanf("%lf%lf", &x, &y);
    printf("The harmonic mean of x and y is: %f\n", HAR_MEAN(x, y));

    return 0;
}
