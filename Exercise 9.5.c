/* Exercise 9.5.c -- replaces two doubles with the larger one */
#include <stdio.h>
#include <float.h>
void larger_of(double * px, double * py);
int main(void)
{
    double x, y;
    printf("Enter two doubles, otherwise quitting the program:\n");
    while (scanf("%lf%lf", &x, &y))
    {
        printf("x = %f, y = %f before the function.\n", x, y);
        larger_of(&x, &y);
        printf("x = %f, y = %f after the function.\n", x, y);
        printf("Enter two doubles, otherwise quitting the program:\n");
    }

    return 0;
}

void larger_of(double * px, double * py)
{
    if (*px - *py > DBL_EPSILON)
    {
        *py = *px;
    }
    else if (*py - *px > DBL_EPSILON)
    {
        *px = *py;
    }
}
