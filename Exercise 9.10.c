/* Exercise 9.10.c -- to_base_n() */
#include <stdio.h>
void to_base_n(unsigned long dec, int n);
int main(void)
{
    unsigned long number;
    int n;

    printf("Enter an integer and the radiix (<= 10) (q to quit):\n");
    while (scanf("%lu%d", &number, &n) == 2)
    {
        printf("Radiix %d equivalent: ", n);
        to_base_n(number, n);
        putchar('\n');
        printf("Enter an integer and the radiix (<= 10) (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}
void to_base_n(unsigned long dec, int n) /* recursive function */
{
    int r;
    r = dec % n;
    if (dec >= n)
        to_base_n(dec / n, n);
    putchar(r + '0');
}
