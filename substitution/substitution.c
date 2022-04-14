#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int only_alpha(string);
char rotate(char, int);

int main(int argc, string argv[])
{
    //check that CLA is valid - just one and every character a digit
    //check that CLA is valid - just one and every character a digit
    if (argc != 2 || only_alpha(argv[1]) == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //check contains each letter once....


    //Convert argv[1] from a string to an int
    int cipher = atoi(argv[1]);


    //Ask the user for the plain text input
    string plaintext = get_string("plaintext:  ");
    int l = strlen(plaintext);


    //print the output
    printf("ciphertext:  ");
    for (int i = 0; i < l; i++)
    {
        printf("%c", rotate(plaintext[i], cipher));
    }
    printf("\n");
}


//new function to cycle through a string and check if each character is alphabetical based on ASCII chart
int only_alpha(string s)
{
    int l = strlen(s);

    for (int i = 0; i < l; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

//new function to turn a character of plaintext into a cipher code by moving it n times
//code uses % to make sure it cycles back to start of alphabet once it has passed z
//numbers reflect ASCII chart
char rotate(char c, int n)
{
    int x = c + n;

    if (isupper(c))
    {
        if (x > 90)
        {
            do
            {
                x = (x % 90) + 64;
            }
            while (x > 90);
        }
        return x;
    }
    if (islower(c))
    {
        if (x > 122)
        {
            do
            {
                x = (x % 122) + 96;
            }
            while (x > 122);
        }
        return x;
    }
    else
    {
        return c;
    }
}