/* Exercise 6.16.c -- compare two methods of investments */
#include <stdio.h>
#include <float.h>
int main(void)
{
    double origin = 100.0, rate1 = 0.1, rate2 = 0.05;
    double total1 = origin, total2 = origin;
    int i = 0;
    
    do
    {
        total1 += origin * rate1;
        total2 *= (1 + rate2);
        i++;
        printf("%.3f  %.3f in Year %d\n", total1, total2, i);
    } while (total1 - total2 > DBL_EPSILON);
    
    return 0;
}
