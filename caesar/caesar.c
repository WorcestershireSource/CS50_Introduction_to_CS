#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //convert CLA string into int
    int ciphercode = atoi(argv[1]);

    //check if CLA input is valid
    if (argc != 2 || ciphercode < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //get plaintext from user
    string plaintext = get_string("plaintext:  ");

    int l = strlen(plaintext);

    int ciphertext[l];


    for(int i = 0; i < l; i++)
    {
        if(islower(plaintext[i]))
        {
            ciphertext[i] = ((int) plaintext[0] + ciphercode) % 122;
            printf("%ch\n", ciphercode);
        }
            //if(isupper(ciphertext[i]))
            //{
            //    ciphertext[i] = (plaintext[i] + argv[2]) % 90;
            //}

        }


}

