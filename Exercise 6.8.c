/* Exercise 6.8.c -- calculates (a - b) / (a * b) */
#include <stdio.h>
int main(void)
{
    float num1, num2, result;

    printf("Enter two floating-point numbers: \n");
    while (scanf("%f%f", &num1, &num2) == 2)
    {
        result = (num1 - num2) / (num1 * num2);
        printf("(%g - %g) / (%g * %g) = %g\n", num1, num2, num1, num2, result);
        printf("Enter next two numbers to continue, nonnumeric value to quit: \n");
    }

    return 0;
}
