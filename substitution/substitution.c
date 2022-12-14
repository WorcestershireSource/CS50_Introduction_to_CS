#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int only_alpha(string);
int rotate(char);

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

    //check key in CLA contains each letter once....
    int key_check = 0;
    for (int i = 65; i < 91; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (toupper(argv[1][j]) == i)
            {
                key_check++;
            }
        }
        if (key_check != i - 64)
        {
            printf("Key must contain 26 unique characters\n");
            return 1;
        }
    }


    //Convert argv[1] from a string to an int
    int cipher = atoi(argv[1]);


    //Ask the user for the plain text input
    string plaintext = get_string("plaintext:  ");
    int l = strlen(plaintext);


    //print the output
    printf("ciphertext:  ");
    for (int i = 0; i < l; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(argv[1][rotate(plaintext[i])]));
        }
        if (islower(plaintext[i]))
        {
            printf("%c", tolower(argv[1][rotate(plaintext[i])]));
        }
        if (isalpha(plaintext[i]) == 0)
        {
            printf("%c", plaintext[i]);
        }
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
int rotate(char c)
{
    if (isupper(c))
    {
        int x = c - 65;
        return x;
    }
    if (islower(c))
    {
        int x = c - 97;
        return x;
    }
    else
    {
        return 27;
    }
}