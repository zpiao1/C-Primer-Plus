/* Exercise 14.6.c -- Softball statistics */
#include <stdio.h>
#include <stdlib.h>
#define TEAMMEM 3
#define NAMELEN 10
typedef struct sbplayer {
    int num;
    char first[NAMELEN];
    char last[NAMELEN];
    int bats;
    int hits;
    int walks;
    int RBIs;
    float bat_ave;
} PLAYER;

int main(void)
{
    PLAYER team[TEAMMEM];
    int i, temp_scr, count;
    int sum_bats = 0.0;
    int sum_hits = 0.0;
    int sum_walks = 0.0;
    int sum_RBIs = 0.0;
    float team_bat_ave = 0.0;
    FILE * fp;

    fp = fopen("softball.dat", "r");
    if (!fp)
    {
        fprintf(stderr, "Cannot open %s!\n", "softball.bat");
        exit(EXIT_FAILURE);
    }

    // Initializing the numbers
    for (i = 0; i < TEAMMEM; i++)
    {
        team[i].num = i;
        team[i].bats = 0;
        team[i].hits = 0;
        team[i].walks = 0;
        team[i].RBIs = 0;
        team[i].bat_ave = 0.0;
    }
    // Read in data
    while (!feof(fp))
    {
        fscanf(fp, "%d", &i);
        fscanf(fp, "%s %s", team[i].first, team[i].last);
        fscanf(fp, "%d", &temp_scr);
        team[i].bats += temp_scr;
        fscanf(fp, "%d", &temp_scr);
        team[i].hits += temp_scr;
        fscanf(fp, "%d", &temp_scr);
        team[i].walks += temp_scr;
        fscanf(fp, "%d", &temp_scr);
        team[i].RBIs += temp_scr;
    }
    // Generate statistic data
    for (i = 0; i < TEAMMEM ; i++)
    {
        sum_bats += team[i].bats;
        sum_hits += team[i].hits;
        sum_walks += team[i].walks;
        sum_RBIs += team[i].RBIs;
        team[i].bat_ave = (float)team[i].hits / team[i].bats;
    }
    team_bat_ave = (float)sum_hits / sum_bats;
    printf("|  # |        Name        | Bats | Hits | Walks | RBIs | Batting Average |\n");
    for (i = 0; i < TEAMMEM; i++)
    {
        printf("| %2d |%9s %9s |", i, team[i].first, team[i].last);
        printf(" %4d | %4d | %5d | %4d |", team[i].bats, team[i].hits, team[i].walks,
               team[i].RBIs);
        printf(" %15.1f |\n", team[i].bat_ave);
    }
    printf("|           Team          | %4d | %4d | %5d | %4d | %15.1f |\n",
           sum_bats, sum_hits, sum_RBIs, sum_walks, team_bat_ave);
    fclose(fp);

    return 0;
}
