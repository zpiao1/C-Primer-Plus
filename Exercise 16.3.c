/* Exercise 16.3.c -- polar coordinates to rectangular coordinates */
#include <stdio.h>
#include <math.h>
#define DEG2RAD atan(1)/45

typedef struct _rect {
    double x;
    double y;
} Rect;

typedef struct _pola {
    double r;
    double A;
} Pola;

Rect polar2rect(Pola * ptr_p);

int main(void)
{
    Rect r;
    Pola p;

    puts("Enter the magnitude and the angle (in degrees): ");
    scanf("%lf%lf", &p.r, &p.A);
    r = polar2rect(&p);
    printf("The vector in rectangular coordinates is :(%f, %f)\n",
           r.x, r.y);

    return 0;
}

Rect polar2rect(Pola * ptr_p)
{
    Rect rect;
    rect.x = (ptr_p->r) * sin(ptr_p->A * DEG2RAD);
    rect.y = (ptr_p->r) * cos(ptr_p->A * DEG2RAD);

    return rect;
}
