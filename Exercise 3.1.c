/* Exercise 3.1.c examines the overflow of integers and overflow and
    underflow of float numbers */
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void)
{
    printf("Integer overflow: %d\n", INT_MAX + 1);
    printf("Floating-point overflow: %f\n", FLT_MAX + 1.0);
    printf("Floating-point underflow: %f\n", FLT_MIN - 1.0);
    return 0;
}
