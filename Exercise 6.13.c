/* Exercise 6.13.c -- stores powers of 2 in array */
#include <stdio.h>
int power_2(int exp);
int main(void)
{
    const int SIZE = 8;
    int powers[SIZE];
    int count;

    for (count = 0; count < SIZE; count++)
        powers[count] = power_2(count + 1);
    count = 7;
    do
    {
        printf("2^%d = %d\n", count + 1, powers[count]);
        count--;
    } while (count >= 0);

    return 0;
}

int power_2(int exp)
{
    int i, product = 1;
    for (i = 1; i <= exp; i++)
        product *= 2;

    return product;
}
