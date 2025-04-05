#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int total_letters(string text);
int total_words(string text);
int total_lines(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = (100.0 * total_letters(text)) / total_words(text);
    float S = (100.0 * total_lines(text)) / total_words(text);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int x = round(index);

    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }
}

int total_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int total_words(string text)
{
    int spaces = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
        }
    }
    return spaces + 1;
}

int total_lines(string text)
{
    int line_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            line_count++;
        }
    }
    return line_count;
}
