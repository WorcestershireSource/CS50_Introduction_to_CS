#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 || isalpha(argv[2]) != 0 || argv[2] < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string input = get_string("plaintext:  ");

        int l = strlen(input);

        string ciphertext[l];

        for(int i = 0; i < l; i++)
        {
            if(islower(ciphertext[i]))
            {
                ciphertext[i] = ((int) input[i] + (int) argv[2]) % 122;
            }
            if(isupper(ciphertext[i]))
            {
                ciphertext[i] = ((int) input[i] + (int) argv[2]) % 90;
            }

        }

    }

}