/* Exercise 11.1.c -- reads next n chars from
   input and stores in a char[] provided */
#include <stdio.h>
#define SIZE 10
void get_n_char(char * str, int n);
int main(void)
{
    char strin[SIZE];

    puts("Enter strin: ");
    get_n_char(strin, SIZE - 1);
    puts("strin is:");
    puts(strin);
}

void get_n_char(char * str, int n)
{
    int i;
    for (i = 0; i < n; i++)
        str[i] = getchar();
    str[i] = '\0';
}
