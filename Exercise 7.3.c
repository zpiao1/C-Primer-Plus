// Exercise 7.3.c -- count odd and even numbers and calculate their average.
#include <stdio.h>
int main(void)
{
    int number, n_odd, n_even;
    double sum_odd, sum_even;

    n_odd = n_even = 0;
    sum_odd = sum_even = 0.0;

    printf("Enter numbers. 0 to quit.\n");
    scanf("%d", &number);
    while (number != 0)
    {
        if (number % 2 == 0)
        {
            n_even++;
            sum_even += number;
        }
        else
        {
            n_odd++;
            sum_odd += number;
        }
        scanf("%d", &number);
    }
    printf("%d odd number%s, average is %g\n", n_odd, (n_odd == 1) ? "" : "s", sum_odd / n_odd);
    printf("%d even number%s, average is %g\n", n_even, (n_even == 1) ? "" : "s", sum_even / n_even);

    return 0;
}
