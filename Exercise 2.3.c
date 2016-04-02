/* Exercise 2.3.c converting age in years to days */
#include <stdio.h>
int main(void)
{
    int age_in_years = 19;
    int age_in_days = age_in_years * 365;

    printf("My age in years is %d, and in days is %d\n", age_in_years, age_in_days);

    return 0;
}
