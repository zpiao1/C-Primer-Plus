/* Exercise 13.12.c -- prints a pic according to the file */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char dark[] = " .':~*=&%#";
    int rows = 20, cols = 30;
    char pic[rows][cols+1];
    int info[rows][cols];
    int i, j;
    FILE *fp1, *fp2;

    fp1 = fopen("num.dat", "r");
    fp2 = fopen("pic.txt", "w");
    if (!fp1)
        fprintf(stderr, "Cannot open num.dat\n");
    if (!fp2)
        fprintf(stderr, "Cannot open pic.txt\n");
    // Get the picture
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols + 1; j++)
        {
            if (j < cols)
            {
                fscanf(fp1, "%d", &info[i][j]);
                pic[i][j] = dark[info[i][j]];
            }
            else
                pic[i][j] = '\0';
        }
    for (i = 0; i < rows; i++)
    {
        puts(pic[i]);
        fprintf(fp2, "%s\n", pic[i]);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
