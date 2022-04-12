#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters (string);
int count_words (string);
int count_sentences (string);

int main(void)
{
    // prompt user for string with get_string
    string input = get_string("Text: ");

    //printf("%i letters\n", count_letters(input));
    //printf("%i words\n", count_words(input));
    //printf("%i sentences\n", count_sentences(input));


    //calc average no of letters per 100 word
    float l = (count_letters(input) / count_words(input)) * 100.0;

    //calc average no of sentences per 100 word
    float w = (count_sentences(input) / count_words(input)) * 100.0;

    //index = 0.0588 * L - 0.296 * S - 15.8
    float findex = (0.0588 * l) - (0.296 * w) - 15.8;
    int index = round(findex);

    // print output "grade X" - as rounded int -
    if(index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if(index > 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
        return 0;
    }
    if(index > 15)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        return 1;
    }


}


int count_letters (string s)
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

int count_words (string s)
{
    //count number of words - anything separated by a space
    int l = strlen(s);
    int words = 1;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 32 )
        {
            words++;
        }
    }
    return words;
}

int count_sentences (string s)
{
    // count number of sentences - .? or! marks end of a sentence
    int l = strlen(s);
    int sentences = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 33 || s[i] == 46 || s[i] == 63 )
        {
            sentences++;
        }
    }
    return sentences;
}