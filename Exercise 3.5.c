/* Exercise 3.5.c -- converts years to seconds */
#include <stdio.h>
int main(void)
{
    int age_in_years;
    printf("Enter your age in years: ");
    scanf("%d", &age_in_years);
    double age_in_seconds = 3.156e7 * age_in_years;
    printf("Your age in seconds is: %g", age_in_seconds);
    return 0;
}
