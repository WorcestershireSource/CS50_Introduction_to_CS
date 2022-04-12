#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    // prompt user for string with get_string
    string input = get_string("Text: ");

    //calculate reading index score = 0.0588 * L - 0.296 * S - 15.8
    float l = ((float) count_letters(input) / (float) count_words(input)) * 100.0;
    float w = ((float) count_sentences(input) / (float) count_words(input)) * 100.0;
    float index = round((0.0588 * l) - (0.296 * w) - 15.8);

    // print output "grade X" - as rounded int
    // special outputs for values below 1 and 16+
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
        return 0;
    }
    if (index > 15)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        return 1;
    }


}


int count_letters(string s)
{
    // count number of letters (a to z upper and lower))

    int l = strlen(s);
    int letters = 0;
    for (int i = 0; i < l; i++)
    {
        if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    //count number of words - anything separated by a space
    int l = strlen(s);
    int words = 1;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string s)
{
    // count number of sentences - .? or! marks end of a sentence
    int l = strlen(s);
    int sentences = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}