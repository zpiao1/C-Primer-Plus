/* Exercise 5.4.c -- converts centimeters to feet and inches */
#include <stdio.h>
int main(void)
{
    double heightCM, heightIn, inRemainder;
    int ft;
    const int IN_PER_FT = 12;
    const double CM_PER_IN = 2.54;

    printf("Enter a height in centimeters: ");
    scanf("%lf", &heightCM);
    heightIn = heightCM / CM_PER_IN;
    ft = (int)(heightIn / IN_PER_FT);
    inRemainder = heightIn - ft * IN_PER_FT;
    printf("%.1f cm = %d feet, %.1f inches\n", heightCM, ft, inRemainder);
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%lf", &heightCM);
    while (heightCM > 0)
    {
        heightIn = heightCM / CM_PER_IN;
        ft = (int)(heightIn / IN_PER_FT);
        inRemainder = heightIn - ft * IN_PER_FT;
        printf("%.1f cm = %d feet, %.1f inches\n", heightCM, ft, inRemainder);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%lf", &heightCM);
    }
    printf("bye");

    return 0;
}
