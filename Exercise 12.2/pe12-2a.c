// pe12-2a.c
#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance = 0.0;
static double fuel = 0.0;

void set_mode(int in_mode)
{
    if (in_mode == 0 || in_mode == 1)
        mode = in_mode;
    else
    {
        printf("Invalid mode specified. Mode ");
        printf((mode == 0) ? "0(metric)" : "1(US)");
        printf(" used.\n");
    }
}

void get_info(void)
{
    printf("Enter distance traveled in ");
    printf((mode == 0) ? "kilometers: " : "miles: ");
    scanf("%lf", &distance);

    printf("Enter fuel consumed in ");
    printf((mode == 0) ? "liters: " : "gallons: ");
    scanf("%lf", &fuel);
}

void show_info(void)
{
    printf("Fuel consumption is ");
    if (mode == 0)
        printf("%.2f liters per 100 km.\n",  fuel / distance * 100);
    else
        printf("%.1f miles per gallon.\n", distance / fuel);
}
