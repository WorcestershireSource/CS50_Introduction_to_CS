#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters (string);
int count_words (string);
int count_sentences (string);

int main(void)
{
    // prompt user for string with get_string
    string input = get_string("Text: ");
    printf("%i letters\n", count_letters(input));
    printf("%i words\n", count_words(input));
    printf("%i sentences\n", count_sentences(input));



//calculation

// print output "grade X" - as rounded int -
//if >16 then say 16+
//if <1 say Before Grade 1

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