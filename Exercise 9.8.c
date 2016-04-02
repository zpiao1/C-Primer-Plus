/* Exercise 9.8.c -- extend power() function */
#include <stdio.h>
double power(double base, int exp);
int main(void)
{
    double base;
    int exp;
    printf("Please enter a double as the base"
           " and an integer as the exponent:\n");
    scanf("%lf%d", &base, &exp);
    printf("%f^%d = %f\n", base, exp, power(base, exp));

    return 0;
}

double power(double base, int exp)
{
    int i;
    double product = 1.0;
    if (exp > 0)
    {
        for (i = 1; i <= exp; i++)
            product *= base;
    }
    else if (exp < 0)
    {
        for (i = 1; i <= -exp; i++)
            product /= base;
    }

    return product;
}
