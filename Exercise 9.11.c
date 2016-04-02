/* Exercise 9.11.c -- Fibonacci() using loop */
#include <stdio.h>
int Fibonacci(int n);
int main(void)
{
    int n;
    printf("Enter n to find the nth term in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The %dth term in the sequence is: %d\n", n, Fibonacci(n));

    return 0;
}

int Fibonacci(int n)
{
    int i, pre1 = 1, pre2 = 1;
    int curr = pre2;
    for (i = 3; i <= n; i++)
    {
        curr = pre1 + pre2;
        pre2 = pre1;
        pre1 = curr;
    }

    return curr;
}
