#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int only_alpha(string);
char rotate(char, int);

int main(int argc, string argv[])
{
    //check that CLA is valid
    if (argc != 2 || only_alpha(argv[1]) == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
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

//new function to turn a character of plaintext into a cipher code
//numbers reflect ASCII chart
char rotate(char c, string n)
{
    if (isupper(c))
    {
        int x = c - 64;
        return cipher[x];
    }
    if (islower(c))
    {
        int x = c - 96;
        return cipher[x];
    }
    else
    {
        return c;
    }
}