/* Exercise 6.17.c -- from heaven to hell */
#include <stdio.h>
#include <float.h>
int main(void)
{
    double origin = 1E6;
    const double RATE = 0.08, WITHDRAWAL = 100000.0;
    int i = 0;

    do
    {
        origin *= (1 + RATE);
        if (origin > WITHDRAWAL)
            origin -= WITHDRAWAL;
        else
            origin = 0;
        i++;
        printf("Remaining after year %d: %.3f\n", i, origin);
    } while (origin > DBL_EPSILON);

    return 0;
}
