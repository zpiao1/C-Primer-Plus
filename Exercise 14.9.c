/* Exercise 14.9.c -- extension of the a flight structure */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define NAMELEN 20
#define FLIGHTS 4
#define SEATS 12
typedef struct seat {
    int seat_id;
    bool assigned;
    char last[NAMELEN];
    char first[NAMELEN];
    bool confirmed;
} SEAT;

typedef struct plane {
    int flight_num;
    SEAT vacancy[SEATS];
} PLANE;

void eatline(void);
void show_empty_seat_num(const SEAT * seats, int n);
void show_empty_seat_lst(const SEAT * seats, int n);
void show_alpha_lst(const SEAT * seats, int n);
void assign_customer(SEAT * seats, int n);
void del_assign(SEAT * seats, int n);
void confirm(SEAT * seats, int n);
int findint(int * arr, int n, int integer);
char * s_gets(char * st, int n);

int main(void)
{
    char choice;
    PLANE flights[FLIGHTS];
    int i, j;
    int fl_num;
    int index;
    FILE * fp;
    int flight_nums[] = {102, 311, 444, 519};
    fp = fopen("flight2.dat", "r+b");
    if (!fp)
    {
        fputs("Can't open flight2.dat", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(fp);

    if (getc(fp) == EOF)
    {
        for (i = 0; i < FLIGHTS; i++)
        {
            flights[i].flight_num = flight_nums[i];
            for (j = 0; j < SEATS; j++)
            {
                flights[i].vacancy[j].seat_id = j;
                flights[i].vacancy[j].assigned = false;
                flights[i].vacancy[j].confirmed = false;
                flights[i].vacancy[j].first[0] = '\0';
                flights[i].vacancy[j].last[0] = '\0';
            }
        }
        puts("Done for initialization.");
    }
    else
    {
        fread(flights, sizeof(PLANE), FLIGHTS, fp);

        puts("We have Flights 102, 311, 444, 519");
        puts("Enter the flight number, non-numeric value to quit:");
        while (scanf("%d", &fl_num) == 1)
        {
            eatline();
            if (index = findint(flight_nums, FLIGHTS, fl_num) == -1)
            {
                puts("No such flight number. Enter again:");
                continue;
            }
            do
            {
                puts("To choose a function, enter its letter label:");
                puts("a) Show number of empty seats");
                puts("b) Show list of empty seats");
                puts("c) Show alphabetical list of seats");
                puts("d) Assign a customer to a seat assignment");
                puts("e) Delete a seat assignment");
                puts("f) Confirming a seat assignment");
                puts("g) Back to the top level menu");
                choice = getchar();
                eatline();
                if (choice != 'g')
                    switch (choice)
                    {
                        case 'a' :
                            show_empty_seat_num(flights[index].vacancy, SEATS);
                            break;
                        case 'b' :
                            show_empty_seat_lst(flights[index].vacancy, SEATS);
                            break;
                        case 'c' :
                            show_alpha_lst(flights[index].vacancy, SEATS);
                            break;
                        case 'd' :
                            assign_customer(flights[index].vacancy, SEATS);
                            break;
                        case 'e' :
                            del_assign(flights[index].vacancy, SEATS);
                            break;
                        case 'f' :
                            confirm(flights[index].vacancy, SEATS);
                        default :
                            puts("Wrong choice!");
                    }
            } while (choice != 'g');
            puts("Enter the next flight number, non-numeric value to quit:");
        }
    }



    rewind(fp);
    fwrite(flights, sizeof(PLANE), FLIGHTS, fp);
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
        printf("Confirmed: ");
        (temp[i]->confirmed) ? printf("Yes") : printf("No");
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
            seats[i].assigned = false;
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
    eatline();
    for (i = 0; i < n; i++)
    {
        if (seats[i].seat_id == id)
        {
            if (seats[i].assigned)
            {
                seats[i].assigned = false;
                seats[i].confirmed = false;
            }
            else
                puts("The seat is not assigned to anyone.");
            return;
        }
    }
    puts("Sorry, your seat ID is not found.");
}

void confirm(SEAT * seats, int n)
{
    int i, id;
    puts("Enter your seat ID:");
    scanf("%d", &id);
    eatline();
    for (i = 0; i < n; i++)
    {
        if (seats[i].seat_id == id)
        {
            if (!seats[i].confirmed && seats[i].assigned)
                seats[i].confirmed = true;
            else if (seats[i].confirmed)
                puts("The seat has been confirmed.");
            else if (!seats[i].assigned)
                puts("You need to be assigned to the seat first.");
            return;
        }
    }
    puts("Sorry, your seat ID is invalid.");
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

int findint(int * arr, int n, int integer)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == integer)
            return i;
    return -1;
}

