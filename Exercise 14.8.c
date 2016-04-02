/* Exercise 14.8.c -- A flight structure */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define NAMELEN 20
#define SEATS 12
typedef struct seat {
    int seat_id;
    bool assigned;
    char last[NAMELEN];
    char first[NAMELEN];
} SEAT;

void eatline(void);
void show_empty_seat_num(const SEAT * seats, int n);
void show_empty_seat_lst(const SEAT * seats, int n);
void show_alpha_lst(const SEAT * seats, int n);
void assign_customer(SEAT * seats, int n);
void del_assign(SEAT * seats, int n);
char * s_gets(char * st, int n);
int main(void)
{
    char choice;
    SEAT flight[SEATS];
    int i;
    FILE * fp;

    fp = fopen("flight.dat", "r+b");
    if (!fp)
    {
        fputs("Can't open flight.dat", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    fread(flight, sizeof(SEAT), SEATS, fp);

    do
    {
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Quit");
        choice = getchar();
        eatline();
        if (choice != 'f')
            switch (choice)
            {
                case 'a' :
                    show_empty_seat_num(flight, SEATS);
                    break;
                case 'b' :
                    show_empty_seat_lst(flight, SEATS);
                    break;
                case 'c' :
                    show_alpha_lst(flight, SEATS);
                    break;
                case 'd' :
                    assign_customer(flight, SEATS);
                    break;
                case 'e' :
                    del_assign(flight, SEATS);
                    break;
                default :
                    puts("Wrong choice!");
            }
    } while (choice != 'f');

    rewind(fp);
    fwrite(flight, sizeof(SEAT), SEATS, fp);
    fclose(fp);

    return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
void show_empty_seat_num(const SEAT * seats, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (!seats[i].assigned)
            count++;

    printf("There are currently %d empty seats.\n", count);
}

void show_empty_seat_lst(const SEAT * seats, int n)
{
    int i;

    puts("The list of empty seats:");
    for (i = 0; i < n; i++)
        if (!seats[i].assigned)
            printf("Seat ID: %d\n", seats[i].seat_id);
}

void show_alpha_lst(const SEAT * seats, int n)
{
    const SEAT * temp[SEATS]; // use array of pointers to sort
    const SEAT * inter;       // intermediate var to interchange two ptr-to-SEAT
    int count = 0;
    int i, j;

    for (i = 0; i < n; i++)
        if (seats[i].assigned)
        {
            temp[count] = seats + i;
            count++;
        }

    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
            if (strcmp(temp[i]->first, temp[j]->first) > 0)
            {
                inter = temp[i];
                temp[i] = temp[j];
                temp[j] = inter;
            }

    puts("Alphabetical list of seats: ");
    for (i = 0; i < count; i++)
    {
        printf("Seat ID: %d\n", temp[i]->seat_id);
        printf("Name: %s %s\n", temp[i]->first, temp[i]->last);
        puts("");
    }
}

void assign_customer(SEAT * seats, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!seats[i].assigned)
        {
            printf("Seat ID: %d\n", i);
            puts("Enter your first name:");
            s_gets(seats[i].first, NAMELEN);
            puts("Enter your last name:");
            s_gets(seats[i].last, NAMELEN);
            seats[i].assigned = true;
            eatline();
            return;
        }
    }
    puts("Sorry, no vacancy.");
    eatline();
}

void del_assign(SEAT * seats, int n)
{
    int id, i;

    puts("Enter your seat ID:");
    scanf("%d", &id);
    for (i = 0; i < n; i++)
    {
        if (seats[i].seat_id == id)
        {
            if (seats[i].assigned)
                seats[i].assigned = false;
            else
                puts("The seat is not assigned to anyone.");
            return;
        }
    }
    puts("Sorry, your seat ID is not found.");
    eatline();
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
