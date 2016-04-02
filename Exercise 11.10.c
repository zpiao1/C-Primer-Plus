/* Exercise 11.10.c -- removes all the spaces */
#include <stdio.h>
#define SIZE 50
char * s_gets(char * st, int n);
void remove_space(char * st);
int main(void)
{
    char string[SIZE];

    puts("Enter a line, empty line to quit");
    s_gets(string, SIZE);
    while (string[0] != '\0')
    {
        remove_space(string);
        puts(string);
        s_gets(string, SIZE);
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void remove_space(char * st)
{
    int i = 0, j = 0;
    while (st[j] != '\0')
    {
        if (st[j] != ' ')
        {
            st[i] = st[j];
            i++;
        }
        j++;
    }
    st[i] = '\0';
}
