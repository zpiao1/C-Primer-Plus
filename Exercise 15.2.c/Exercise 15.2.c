/* Exercise 15.2.c -- bitwise operations on command-line arguments */
#include <stdio.h>
#include <stdlib.h>
#define LEN 21
char * itobs(int n, char * ps);
int bstoi(char * bs);
int main(int argc, char * argv[])
{
    int result, operand1, operand2;
    char res_str[LEN];

    if (argc != 3)
    {
        printf("Usage: %s binStr1 binStr2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    operand1 = bstoi(argv[1]);
    operand2 = bstoi(argv[2]);

    result = ~operand1;
    printf("~%s = %s\n", argv[1], itobs(result, res_str));

    result = ~operand2;
    printf("~%s = %s\n", argv[2], itobs(result, res_str));

    result = operand1 & operand2;
    printf("%s & %s = %s\n", argv[1], argv[2], itobs(result, res_str));

    result = operand1 | operand2;
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(result, res_str));

    result = operand1 ^ operand2;
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(result, res_str));

    return 0;
}

char * itobs(int n, char * ps)
{
    int i;
    for (i = LEN - 1; i >= 0; i--, n >>= 1)
        ps[i] = '0' + (n & 1);

    ps[LEN] = '\0';

    return ps;
}

int bstoi(char * bs)
{
    int i;
    int value = 0;

    for (i = 0; bs[i] != '\0'; i++)
    {
        if (bs[i] > '1' || bs[i] < '0')
            return -1;
        value <<= 1;
        value |= (bs[i] - '0');
    }

    return value;
}
