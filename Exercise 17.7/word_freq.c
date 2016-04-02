/* word_freq.c -- using binary search tree to store word frequency */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
Item MakeItem(char * temp);
void ShowItem(Item item);
char ShowMenu(void);
char * ToLower(char * str);
int main(void)
{
    char temp[SLEN];
    FILE * fp;
    Item item;
    Tree wordtree;
    char choice;

    fp = fopen("text.txt", "r");
    if (!fp)
    {
        fprintf(stderr, "Cannot open the fild!\n");
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordtree);
    while (fscanf(fp, "%20s", temp) != EOF && (!TreeIsFull(&wordtree)))
    {
        item = MakeItem(temp);
        AddItem(&item, &wordtree);
    }
    choice = ShowMenu();
    while (choice != 'q')
    {
        switch (choice)
        {
            case 't' : Traverse(&wordtree, ShowItem);
                break;
            case 'w' : SearchWord(&wordtree, ShowItem);
                break;
            default : puts("Unknown command.");
        }
        choice = ShowMenu();
    }

    puts("Bye!");

    DeleteAll(&wordtree);
    fclose(fp);
    return 0;
}

Item MakeItem(char * temp)
{
    Item newItem;
    int length = strlen(temp);

    if (!isalpha(temp[length - 1]))
        temp[length - 1] = '\0';
    temp = ToLower(temp);
    newItem.word = (char *)malloc(sizeof(char) * strlen(temp) + 1);
    strcpy(newItem.word, temp);
    newItem.freq = 1;

    return newItem;
}

void ShowItem(Item item)
{
    printf("%s: %d\n", item.word, item.freq);
}

char ShowMenu(void)
{
    char option;

    puts("Choose one of the following:");
    puts("t) Show the list of words");
    puts("w) Search the word in the list");
    puts("q) quit");
    do
    {
        option = getchar();
        while (getchar() != '\n')
            continue;
    } while (strchr("qtw", option) == NULL);

    return option;
}

char * ToLower(char * str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
    return str;
}
