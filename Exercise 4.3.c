/* Exercise 4.3.c -- prints floating-point numbers in specified formats. */
#include <stdio.h>
int main(void)
{
    float number;
    printf("Enter a floating-point number: ");
    scanf("%f", &number);
    printf("a. The input is %.1f or %.1e\n", number, number);
    printf("Enter another floating-point number: ");
    scanf("%f", &number);
    printf("b. The input is %+.3f or %.3E\n", number, number);

    return 0;
}
