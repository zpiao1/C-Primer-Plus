/* Exercise 14.5.c -- a giant structure holding a class of students */
#include <stdio.h>
#define NAMELEN 20
#define CSIZE 4
#define SSIZE 3
typedef struct name {
    char first_name[NAMELEN];
    char second_name[NAMELEN];
} NAME;

typedef struct student {
    NAME stu_name;
    float grade[3];
    float ave;
} STUDENT;

void get_score(STUDENT * students, int n);
void calc_ave(STUDENT * students, int n);
void print_info(STUDENT * students, int n);
void print_class_ave(STUDENT * students, int n);
int main(void)
{
    STUDENT stdnts[CSIZE] =
    {
        {{"Dana Frazier", "Henry Perez"}},
        {{"Doyle Ward", "Maggie	Hunter"}},
        {{"Alton Rowe", "Bryant Bates"}},
        {{"Emily Boone", "Genevieve Burgess"}}
    };

    get_score(stdnts, CSIZE);
    calc_ave(stdnts, CSIZE);
    print_info(stdnts, CSIZE);
    print_class_ave(stdnts, CSIZE);

    return 0;
}

void get_score(STUDENT * students, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("Student name: %s\n", students[i].stu_name.first_name);
        printf("Enter the three scores:\n");
        for (j = 0; j < SSIZE; j++)
            scanf("%f", &students[i].grade[j]);
    }
}

void calc_ave(STUDENT * students, int n)
{
    int i, j;
    float sum = 0.0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < SSIZE; j++)
            sum += students[i].grade[j];
        students[i].ave = sum / SSIZE;
        sum = 0.0;
    }
}

void print_info(STUDENT * students, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("First name: %s\n", students[i].stu_name.first_name);
        printf("Second name: %s\n", students[i].stu_name.second_name);
        printf("Scores: ");
        for (j = 0; j < SSIZE; j++)
            printf("%f ", students[i].grade[j]);
        printf("\nAverage score: %f\n", students[i].ave);
    }
}

void print_class_ave(STUDENT * students, int n)
{
    int i, j;
    float total = 0.0;
    float class_ave[SSIZE];
    for (j = 0; j < SSIZE; j++)
    {
        for (i = 0; i < n; i++)
            total += students[i].grade[j];
        class_ave[j] = total / n;
        total = 0.0;
    }

    printf("The class average: ");
    for (j = 0; j < SSIZE; j++)
        printf("%f ", class_ave[j]);
    printf("\n");
}
