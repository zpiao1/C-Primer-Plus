/* Exercise 15.1.c -- converts a binary string to a numeric value. */
#include <stdio.h>
#include <string.h>
#define LEN 41
int bin_str_to_int(const char * bin_str);
char * s_gets(char * st, int n);
int main(void)
{
    char bin_str[LEN];
    puts("Enter the binary string:");
    s_gets(bin_str, LEN);
    printf("The corresponding value is: %d\n", bin_str_to_int(bin_str));

    return 0;
}

int bin_str_to_int(const char * bin_str)
{
    unsigned int value = 0;
    int i;
    for (i = 0; bin_str[i] != '\0'; i++)
    {
        if (bin_str[i] < '0' || bin_str[i] > '1')
            return -1;
        value |= (bin_str[i] - '0');
        value <<= 1;
    }
    return (value >> 1);
}

char * s_gets(char * st, int n)
{
    char * ret_val, * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
}
