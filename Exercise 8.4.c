// Exercise 8.4.c -- count average number of letters per word
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int word_cnt = 0, char_cnt = 0;
    char prev_ch, curr_ch;

    printf("Enter a passage to analyse:\n");
    prev_ch = '\n';
    while ((curr_ch = getchar()) != EOF)
    {
        if (isalpha(curr_ch))
        {
            char_cnt++;
            if (prev_ch != '\'' && !isalpha(prev_ch))
                word_cnt++;
        }
        prev_ch = curr_ch;
    }

    printf("Total words: %d\n", word_cnt);
    printf("Total characters (excluding punctuations): %d\n", char_cnt);
    printf("Average characters per word: %d\n", (int)(char_cnt / word_cnt));

    return 0;
}
