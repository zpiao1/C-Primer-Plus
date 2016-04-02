/* Exercise 14.4.c -- a structure of personal information */
#include <stdio.h>
#include <string.h>
#define NAMELEN 20
#define SECNUMLEN 10
#define PERSONS 5
typedef struct name {
    char first_name[NAMELEN];
    char middile_name[NAMELEN];
    char last_name[NAMELEN];
} NAME;

typedef struct person_info {
    char secure_num[SECNUMLEN];
    NAME full_name;
} PERSON_INFO;

void print_by_arr(PERSON_INFO * persons, int n);
void print_by_struct(PERSON_INFO person);

int main(void)
{
    PERSON_INFO persons[PERSONS] =
    {
        {"660032772", {"Ian", "", "Mccleary"}},
        {"019804475", {"Valentine", "Arte", "Hennig"}},
        {"772281302", {"Jaquelyn", "", "Bingham"}},
        {"005662691", {"German", "Abba", "Doman"}},
        {"480112748", {"Tammy", "Kass", "Lasorsa"}},
    };
    int i;

    print_by_arr(persons, PERSONS);
    puts("");

    for (i = 0; i < PERSONS; i++)
        print_by_struct(persons[i]);

    return 0;
}

void print_by_arr(PERSON_INFO * persons, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s, %s ", persons[i].full_name.first_name,
               persons[i].full_name.last_name);
        if (strlen(persons[i].full_name.middile_name) != 0)
            printf("%c. ", persons[i].full_name.middile_name[0]);
        printf("-- %s\n", persons[i].secure_num);
    }
}

void print_by_struct(PERSON_INFO person)
{
    printf("%s, %s ", person.full_name.first_name,
           person.full_name.last_name);
    if (strlen(person.full_name.middile_name) != 0)
        printf("%c. ", person.full_name.middile_name[0]);
    printf("-- %s\n", person.secure_num);
}
