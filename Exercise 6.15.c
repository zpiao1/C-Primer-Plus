/* Exercise 6.15.c -- prints a line backward */
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int SIZE = 255;
    char line[SIZE];
    int i = 0;
    char ch;

    printf("Enter a line, end with a newline. \n");
    scanf("%c", &ch);
    while (ch != '\n')
    {
        line[i] = ch;
        i++;
        scanf("%c", &ch);
    }

    line[i] = '\0';
    for (i = strlen(line) - 1; i >= 0; i--)
    {
        printf("%c", line[i]);
    }
    printf("\n");

    return 0;
}
