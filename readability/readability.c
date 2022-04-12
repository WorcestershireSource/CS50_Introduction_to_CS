#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters (string);
int count_letters (string);

int main(void)
{
    // prompt user for string with get_string
    string input = get_string("Text: ");
    printf("%i letters\n", count_letters(input));







// count number of sentences - .? or! marks end of a sentence


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

int count_letters (string s)
{
    //count number of words - anything separated by a space

}