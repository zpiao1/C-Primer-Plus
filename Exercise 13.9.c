/* Exercise 13.9.c -- add words and keep indexing */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 47

int main(void)
{
    FILE *fp;
    char words[MAX];
    int count;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // get number of words
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        count++;
    rewind(fp);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        count++;
        fprintf(fp, "%d %s\n", count, words);
    }

    puts("File contents:");
    rewind(fp);            /* go back to beginning of file */
    while (fscanf(fp, "%d %s", &count, words) == 2)
        printf("%d %s\n", count, words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
