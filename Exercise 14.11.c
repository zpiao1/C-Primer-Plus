/* Exercise 14.11.c -- use pointers to functions */
#include <stdio.h>
#include <math.h>
#define LEN 100
typedef double (*d_pf_d)(double);
void transform(const double * src, double * tar, int n, d_pf_d pfn);
double inverse(double denom);
double square(double x);
int main(void)
{
    int i;
    double source[LEN], target[LEN];
    for (i = 0; i < LEN; i++)
        source[i] = (double)i;

    puts("sin:");
    transform(source, target, LEN, sin);
    puts("cos:");
    transform(source, target, LEN, cos);
    puts("inverse:");
    transform(source, target, LEN, inverse);
    puts("square:");
    transform(source, target, LEN, square);

    return 0;
}

void transform(const double * src, double * tar, int n, d_pf_d pfn)
{
    int i;
    for (i = 0; i < n; i++)
        tar[i] = (*pfn)(src[i]);

    puts("Source:");
    for (i = 0; i < n; i++)
    {
        printf("%f ", src[i]);
        if (i % 10 == 9)
            puts("");
    }
    puts("Target:");
    for (i = 0; i < n; i++)
    {
        printf("%f ", tar[i]);
        if (i % 10 == 9)
            puts("");
    }
}

double inverse(double denom)
{
    return 1 / denom;
}

double square(double x)
{
    return x * x;
}
