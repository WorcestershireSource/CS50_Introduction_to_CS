#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters (string);

int main(void)
{
    // prompt user for string with get_string
    string input = get_string("Text: ");
    printf("%i letters\n", count_letters(input));






//count number of words - anything separated by a space
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
    for (int i = 0, i < l, i++)
    {
        if ((input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
        {
            letters++;
        }
    }
    return letters;
}