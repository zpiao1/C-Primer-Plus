#include <stdio.h>
int main(void)
{
    double length;
    printf("Enter an inch value: ");
    scanf("%lf", &length);
    printf("The length in centimeters is: %g", length*2.54);
    return 0;
}
