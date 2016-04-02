/* Exercise 5.7.c -- Calculate the cube of an input number */
#include <stdio.h>
void cube(double x);
int main(void)
{
    double num;
    printf("Enter the number to calculate its cube: ");
    scanf("%lf", &num);
    cube(num);

    return 0;
}

void cube(double x)
{
    double xCubed = x * x * x;
    printf("%f ^ 3 = %f\n", x, xCubed);
}
