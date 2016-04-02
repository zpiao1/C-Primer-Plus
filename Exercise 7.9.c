// Exercise 7.9.c -- displays prime numbers
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int n;
    bool isPrime;

    printf("Enter n to find the prime numbers: \n");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
        }
        if (isPrime)
            printf("%d\t", i);
    }

    return 0;
}
