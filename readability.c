#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    if (words == 0)
    {
        printf("No Words Provided. \n");
        return 0;
    }

    // Compute the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int letter_count(string text)
{
    // Return the number of letters in text
    int char_count = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char_count += 1;
        }
    }
    return char_count;
}

int word_count(string text)
{
    // Return the number of words in text
    int blank_count = 1;
    int length = strlen(text);

    for (int i = 1; i < length; i++)
    {
        if (i > 0 && text[i] != ' ' && text[i - 1] == ' ')
        {
            blank_count += 1;
        }
    }
    return blank_count;
}

int sentence_count(string text)
{
    // Return the number of sentences in text
    int punct_count = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            punct_count += 1;
        }
    }
    return punct_count;
}
