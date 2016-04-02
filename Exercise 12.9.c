/* Exercise 12.9 -- reads and shows the words */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 80
char ** make_array(int size);
void get_words(char ** arr, int size);
void print_words(char ** arr, int size);
int main(void)
{
    int size;
    char ** words;
    printf("How many words do you wish to enter? ");
    scanf("%d", &size);

    words = make_array(size);
    if (words)
    {
        get_words(words, size);
        print_words(words, size);
    }

    free(words);
    return 0;
}

char ** make_array(int size)
{
    char ** pt;
    pt = (char **) malloc(size * sizeof(char *));
    if (pt)
        return pt;
}

void get_words(char ** arr, int size)
{
    int i;
    char temp[MAXSIZE];
    printf("Enter %d words now:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%s", temp);
        arr[i] = (char *) malloc((strlen(temp) + 1) * sizeof(char));
        if (!arr[i])
            return;
        strcpy(arr[i], temp);
    }
}

void print_words(char ** arr, int size)
{
    int i;
    printf("Here are your words:\n");
    for (i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
}
