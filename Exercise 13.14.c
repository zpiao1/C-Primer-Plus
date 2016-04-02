/* Exercise 13.12.c -- prints a pic according to the file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 20
#define COL 30
int main(void)
{
    const char dark[] = " .':~*=&%#";
    char pic[ROW][COL+1];
    int info[ROW][COL];
    int i, j;
    int ave;
    FILE *fp1, *fp2;

    fp1 = fopen("num.dat", "r");
    fp2 = fopen("picblur.txt", "w");
    if (!fp1)
        fprintf(stderr, "Cannot open num.dat\n");
    if (!fp2)
        fprintf(stderr, "Cannot open picblur.txt\n");
    // Get the picture
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
                fscanf(fp1, "%d", &info[i][j]);

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
        {
            if (i == 0 && j == 0 &&
                abs(info[i][j] - info[i][j+1]) > 1 &&
                abs(info[i][j] - info[i+1][j]) > 1)             // top-left corner
            {
                ave = (int)((info[i][j+1] + info[i+1][j]) / 2);
                pic[i][j] = dark[ave];
            }
            else if (i == 0 && j == COL-1 &&
                     abs(info[i][j] - info[i+1][j]) > 1 &&
                     abs(info[i][j] - info[i][j-1]) > 1)        // top-right corner
            {
                ave = (int)((info[i+1][j] + info[i][j-1]) / 2);
                pic[i][j] = dark[ave];
            }
            else if (i == ROW-1 && j == 0 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i][j+1]) > 1)        // bottom-left corner
            {
                ave = (int)((info[i-1][j] + info[i][j+1]) / 2);
                pic[i][j] = dark[ave];
            }
            else if (i == ROW-1 && j == COL-1 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i][j-1]) > 1)        // bottom-right corner
            {
                ave = (int)((info[i-1][j] + info[i][j-1]) / 2);
                pic[i][j] = dark[ave];
            }
            else if (i == 0 &&
                     abs(info[i][j] - info[i+1][j]) > 1 &&
                     abs(info[i][j] - info[i][j-1]) > 1 &&
                     abs(info[i][j] - info[i][j+1]) > 1)        // top row
            {
                ave = (int)((info[i+1][j] + info[i][j-1] + info[i][j+1]) / 3);
                pic[i][j] = dark[ave];
            }
            else if (i == ROW-1 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i][j-1]) > 1 &&
                     abs(info[i][j] - info[i][j+1]) > 1)        // bottom row
            {
                ave = (int)((info[i-1][j] + info[i][j-1] + info[i][j+1]) / 3);
                pic[i][j] = dark[ave];
            }
            else if (j == 0 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i+1][j]) > 1 &&
                     abs(info[i][j] - info[i][j+1]) > 1)        // left column
            {
                ave = (int)((info[i-1][j] + info[i+1][j] + info[i][j+1]) / 3);
                pic[i][j] = dark[ave];
            }
            else if (j == COL-1 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i+1][j]) > 1 &&
                     abs(info[i][j] - info[i][j-1]) > 1)        // right column
            {
                ave = (int)((info[i-1][j] + info[i+1][j] + info[i][j-1]) / 3);
                pic[i][j] = dark[ave];
            }
            else if (abs(info[i][j] - info[i][j-1]) > 1 &&
                     abs(info[i][j] - info[i][j+1]) > 1 &&
                     abs(info[i][j] - info[i-1][j]) > 1 &&
                     abs(info[i][j] - info[i+1][j]) > 1)        // not on border
            {
                ave = (int)((info[i][j-1] + info[i][j+1] + info[i-1][j] + info[i+1][j]) / 4);
                pic[i][j] = dark[ave];
            }
            else
                pic[i][j] = dark[info[i][j]];
        }
    for (i = 0; i < ROW; i++)
    {
        pic[i][COL] = '\0';
        puts(pic[i]);
        fprintf(fp2, "%s\n", pic[i]);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}

