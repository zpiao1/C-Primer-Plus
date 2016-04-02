/* Exercise 11.11.c -- sort strings according to user input */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 80
#define NUM 10
void print_list(char *strings[], int num);
void ASCII_sort(char *strings[], int num);
void length_sort(char *strings[], int num);
void first_word(char *strings[], int num);
void get_word(char *st, char *word);
char * s_gets(char * st, int n);
int main(void)
{
    char input[NUM][SIZE];
    char *ptstr[SIZE];
    char choice;
    int ct = 0;


    puts("Enter your choice of options:");  // print the menu
    puts("a) Print the original list of strings.");
    puts("b) Print the strings in ASCII collating sequence.");
    puts("c) Print the strings in order of increasing length.");
    puts("d) Print the strings in order of the length of the first word in the string.");
    puts("e) Quit");
    choice = getchar();
    while (getchar() != '\n')
        continue;
    while (choice != 'e')
    {
        if (choice >= 'a' && choice <= 'd')
        {
            puts("Enter 10 strings, EOF to stop:");
            while (ct < NUM && s_gets(input[ct], SIZE) != NULL
                    && input[ct][0] != '\0')
            {
                ptstr[ct] = input[ct];
                ct++;
            }

            switch (choice)
            {
                case 'a': print_list(ptstr, ct);
                          break;
                case 'b': ASCII_sort(ptstr, ct);
                          print_list(ptstr, ct);
                          break;
                case 'c': length_sort(ptstr, ct);
                          print_list(ptstr, ct);
                          break;
                case 'd': first_word(ptstr, ct);
                          print_list(ptstr, ct);
                          break;
            }
        }
        else
        {
            puts("Enter a correct option");
        }

        puts("Enter your choice of options:");  // print the menu
        puts("a) Print the original list of strings.");
        puts("b) Print the strings in ASCII collating sequence.");
        puts("c) Print the strings in order of increasing length.");
        puts("d) Print the strings in order of the length of the first word in the string.");
        puts("e) Quit");
        choice = getchar();
        while (getchar() != '\n')
            continue;
    }
    puts("Bye.");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void print_list(char *strings[], int num)
{
    int i;
    for (i = 0; i < num;i++)
        puts(strings[i]);
}

void ASCII_sort(char *strings[], int num)
{
    char * temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void length_sort(char *strings[], int num)
{
    int top, seek;
    char * temp;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strlen(strings[top]) > strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void first_word(char *strings[], int num)
{
    int top, seek;
    char * temp;
    char word[SIZE];
    int i;
    int wordlen[NUM];
    for (i = 0; i < num; i++)
    {
        get_word(strings[i], word);
        wordlen[i] = strlen(word);
    }

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (wordlen[top] > wordlen[seek])
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void get_word(char * st, char * word)
{
    int i;
    for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
        word[i] = st[i];
    word[i] = '\0';
}
