/* Exercise 4.8.c -- gasoline conversion between U.S. way and European way */
#include <stdio.h>
#define GALLONS_TO_LITERS 3.785
#define MILES_TO_KILOMETERS 1.609
int main(void)
{
    float distance, gasoline;
    printf("Enter the number of miles traveled and the gasoline consumed: ");
    scanf("%f %f", &distance, &gasoline);
    float milesPerGallon = distance / gasoline;
    printf("The miles-per-gallon value is %.1f\n", milesPerGallon);
    printf("The liters-per-100-km value is %.1f\n", gasoline * GALLONS_TO_LITERS / (100 * distance * MILES_TO_KILOMETERS));

    return 0;
}
