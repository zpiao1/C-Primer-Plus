/* Exercise 11.13.c -- reverses the words provided
   in command-line arguments */
#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;

    for (i = argc - 1; i >= 1; i--)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}
