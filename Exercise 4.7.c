/* Exercise 4.7.c -- compare float and double */
#include <stdio.h>
#include <float.h>
int main(void)
{
    double doubleValue = 1.0 / 3.0;
    float floatValue = 1.0 / 3.0;
    printf("Double: %.4f\nFloat: %.4f\n", doubleValue, floatValue);
    printf("Double: %.12f\nFloat: %.12f\n", doubleValue, floatValue);
    printf("Double: %.16f\nFloat: %.16f\n", doubleValue, floatValue);
    printf("FLT_DIG = %g, DBL_DIG = %g\n", FLT_DIG, DBL_DIG);

    return 0;
}
