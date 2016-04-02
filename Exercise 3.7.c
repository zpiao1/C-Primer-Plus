/* Exercise 3.7.c -- coverting centimeters to inches or vice versa */
#include <stdio.h>
void cm_to_inch(void);
void inch_to_cm(void);
int main(void)
{
    int choice;
    printf("Enter the corresponding number:\n");
    printf("1 -- cm -> inch\n");
    printf("2 -- inch -> cm\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: cm_to_inch(); break;
        case 2: inch_to_cm(); break;
        default: break;
    }

    return 0;
}

void cm_to_inch(void)
{
    double cm, inch;
    printf("Enter cm: ");
    scanf("%lf", &cm);
    inch = cm * 2.54;
    printf("%g cm = %g inches\n", cm, inch);
}

void inch_to_cm(void)
{
    double cm, inch;
    printf("Enter inch: ");
    scanf("%lf", &inch);
    cm = inch / 2.54;
    printf("%g inches = %g cm\n", inch, cm);
}
