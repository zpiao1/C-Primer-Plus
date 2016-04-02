/* Exercise 13.11.c -- finds the string in the file and prints the lines */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 256
int main(int argc, char *argv[])
{
    char temp[STRLEN];
    FILE *fp;
    // Checking command-line arguments
    if (argc != 3)
    {
        printf("Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Trying to open the file
    fp = fopen(argv[2], "r");
    if (!fp)
    {
        fprintf(stderr, "File %s open error\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(temp, STRLEN - 1, fp) != NULL)
    {
        if (strstr(temp, argv[1]) != NULL)
            printf("%s", temp);
    }
    fclose(fp);

    return 0;
}
