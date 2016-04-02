/* Exercise 6.9.c -- calculates (a - b) / (a * b) using a function*/
#include <stdio.h>
float calculation(float a, float b);
int main(void)
{
    float num1, num2, result;

    printf("Enter two floating-point numbers: \n");
    while (scanf("%f%f", &num1, &num2) == 2)
    {
        result = calculation(num1, num2);
        printf("(%g - %g) / (%g * %g) = %g\n", num1, num2, num1, num2, result);
        printf("Enter next two numbers to continue, nonnumeric value to quit: \n");
    }

    return 0;
}

float calculation(float a, float b)
{
    return (a - b) / (a * b);
}
