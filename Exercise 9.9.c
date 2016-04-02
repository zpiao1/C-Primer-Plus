/* Exercise 9.9.c -- extend rpower() function */
#include <stdio.h>
double rpower(double base, int exp);
int main(void)
{
    double base;
    int exp;
    printf("Please enter a double as the base"
           " and an integer as the exponent:\n");
    scanf("%lf%d", &base, &exp);
    printf("%f^%d = %f\n", base, exp, rpower(base, exp));

    return 0;
}

double rpower(double base, int exp)
{
    if (exp == 0)
        return 1.0;
    else if (exp > 0)
        return base * rpower(base, exp - 1);
    else if (exp < 0)
        return 1.0 / (rpower(base, -exp));
}

