/* Exercise 3.8.c -- converting volume units */
#include <stdio.h>
int main(void)
{
    double pint, cup, ounce, tablespoon, teaspoon;
    printf("Enter the volume in cups: ");
    scanf("%lf", &cup);
    pint = cup / 2.0;
    ounce = cup * 8.0;
    tablespoon = ounce * 2.0;
    teaspoon = tablespoon * 3.0;
    printf("%g cups = %g pints = %g ounces = %g tablespoons = %g teaspoons\n",
           cup, pint, ounce, tablespoon, teaspoon);
    return 0;
}
