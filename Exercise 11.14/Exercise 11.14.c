/* Exercise 11.14.c -- raise the double to the
   integer power provided */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    double base, res = 1.0;
    long power;
    int i;
    char *end;

    power = strtol(argv[2], &end, 10);
    base = strtod(argv[1], &end);
    for (i = 0; i < power; i++)
        res *= base;

    printf("Result = %f\n", res);

    return 0;
}
