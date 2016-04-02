// Exercise 8.2.c -- prints the character itself and ASCII decimal value
#include <stdio.h>
void print_pair(char ch);   // handles the printing of the char ASCII pair
int main(void)
{
    char ch;
    int i = 1;

    printf("Enter text to print:\n");
    while ((ch = getchar()) != EOF)
    {
        print_pair(ch);
        if (i == 10)
        {
            printf("\n");
            i = 0;
        }
        else if (ch == '\n')
            printf("\n");
        i++;
    }

    return 0;
}

void print_pair(char ch)
{
    if (ch == '\n')
        printf("\\n %3d ", ch);
    else if (ch == '\t')
        printf("\\t %3d ", ch);
    else if (ch < ' ')
        printf("^%c %3d ", ch + 64, ch);
    else
        printf("%c %3d ", ch, ch);
}
