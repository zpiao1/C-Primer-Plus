/* Exercise 3.4.c -- prints different forms of a floating-point number */
#include <stdio.h>
int main(void)
{
    float value;
    printf("Enter a floating-point value: ");
    scanf("%f", &value);
    printf("fixed-point notation: %f\n", value);
    printf("exponential notation: %e\n", value);
    printf("p notation: %a", value);
    return 0;
}
