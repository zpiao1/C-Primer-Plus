/* Exercise 14.2.c -- print the book inventory in different
   orders */
#include <stdio.h>
#include <string.h>
#include <float.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100          /* maximum number of books */
struct book {               /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
void sort_by_title(struct book * books, int n);
void sort_by_value(struct book * books, int n);
void swap(struct book * bookA, struct book * bookB);

int main(void)
{
    struct book library[MAXBKS];    /* array of book structures */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);

        printf("Sorted by the alphabetical order of the title:\n");
        sort_by_title(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);

        printf("Sorted in the order of increased value:\n");
        sort_by_value(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

char * s_get(char * st, int n)
{
    char * ret_val;
    char * find;

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
    return ret_val;
}

void sort_by_title(struct book * books, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(books[i].title, books[j].title) > 0)
                swap(&books[i], &books[j]);
}

void sort_by_value(struct book * books, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (books[i].value - books[j].value > DBL_EPSILON)
                swap(&books[i], &books[j]);
}

void swap(struct book * bookA, struct book * bookB)
{
    struct book temp;

    temp = *bookA;
    *bookA = *bookB;
    *bookB = temp;
}

char * s_gets(char * st, int n)
{
    char * find, * ret_val;

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
