/* Exercise 14.7.c -- Allowing deletion and modification to the file saving the
   book structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book {
    char title[MAXTITL];
    char author[MAXTITL];
    float value;
    bool todelete;
};
char * s_gets(char * st, int n);
void eatline(void);
void add(struct book * books, int * total, int * valid);
void modify(struct book * books, int total);
void delete(struct book * books, int total, int * valid);
int main(void)
{
    struct book library[MAXBKS];
    int count = 0;              /* count is the total number of books */
    int index, filecount;       /* filecount is the number of books not deleted */
    int valid;
    FILE * pbooks;
    int size = sizeof (struct book);
    char mode;

    if ((pbooks = fopen("newbook.dat", "r+b")) == NULL)
    {
        fputs("Can't open newbook.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size,
                                   1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%d. %s by %s: $%.2f\n", count + 1, library[count].title,
               library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    printf("Count = %d, filecount = %d\n", count, filecount);

    // TODO: print all the books before modifying the array

    puts("Now you can add, modify, or delete the books:");
    printf("Enter \"a\" for add (if not full), \"m\" for modify, \"d\" for delete,");
    puts(" and \"q\" to exit.");
    mode = getchar();
    while (mode != 'q')
    {
        eatline();
        switch (mode)
        {
            case 'a' :
                if (filecount == MAXBKS)
                    puts("The newbook.dat file is full, you can only modify or delete books.");
                else
                    add(library, &count, &filecount);
                break;
            case 'm' :
                modify(library, count);
                break;
            case 'd' :
                delete(library, count, &filecount);
                break;
            default :
                puts("Wrong mode!");
                      break;
        }
        puts("Enter the next mode: ");
        mode = getchar();
    }
    // After changing its content, go back to the beginning of the file
    fclose(pbooks);
    pbooks = fopen("newbook.dat", "wb");
    rewind(pbooks);
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0, valid = 1; index < count; index++)
            if (!library[index].todelete)
            {
                printf("%d. %s by %s: %.2f\n", valid++, library[index].title,
                       library[index].author, library[index].value);
                fwrite(&library[index], size, 1, pbooks);
            }
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val, * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            eatline();
    }

    return ret_val;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void add(struct book * books, int * total, int * valid)
{
    int all = *total - 1;
    int i = 0;

    while (i < MAXBKS && (*valid) <= MAXBKS)
    {
        if (books[i].todelete || i > all)   // the book is to be deleted or
                                            // all the books to be deleted are
                                            // replaced by the newly added books
        {
            puts("Please add new book titles.");
            puts("Press [enter] at the start of a line to stop.");
            if (s_gets(books[i].title, MAXTITL) != NULL &&
                books[i].title[0] != '\0')
            {
                    (*valid)++;                 // number of valid books incremented
                    if (i > all)                // appending new books (all vacancies are filled)
                        (*total) = (*valid);    // all books are not to be deleted
                    puts("Now enter the author.");
                    s_gets(books[i].author, MAXAUTL);
                    puts("Now enter the value.");
                    scanf("%f", &books[i].value);
                    eatline();
                    books[i].todelete = false;
            }
            else                                // Incorrect input or empty line
                break;                          // ends the loop
        }
        i++;
    }
}

void modify(struct book * books, int total)
{
    int i;
    puts("Enter the index of the book you want to modify: ");
    while (scanf("%d", &i) == 1)
    {
        if (i > total)
            puts("Out of range!");
        else if (books[i - 1].todelete)
            puts("The book is to be deleted!");
        // TODO: reverse deletion
        else
        {
            eatline();
            puts("Enter the new title:");
            s_gets(books[i - 1].title, MAXTITL);
            puts("Enter the new author name:");
            s_gets(books[i - 1].author, MAXAUTL);
            puts("Enter the new value:");
            scanf("%f", &books[i - 1].value);
        }
        puts("Enter the next index:");
    }
    eatline();
}

void delete(struct book * books, int total, int * valid)
{
    int i;
    puts("Enter the index of the book you want to delete: ");
    while (scanf("%d", &i) == 1)
    {
        if (i > total)
            puts("Out of range!");
        else if (books[i - 1].todelete)
            puts("The book is to be deleted!");
        else
        {
            eatline();
            books[i - 1].todelete = true;
            (*valid)--;
        }
        puts("Enter the next index, q to quit:");
    }
    eatline();
}
