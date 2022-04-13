#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

    int ciphercode = atoi(argv[1]);
    

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");

    int l = strlen(plaintext);

    string ciphertext;

        //for(int i = 0; i < l; i++)
        //{
            //if(islower(ciphertext[i]))
            ///{
                int x = ((int) plaintext[0] + ciphercode) % 122;
                printf("%i\n", x);
                printf("%i\n", ciphercode);
                //ciphertext[i] = (string) x;
            //}
            //if(isupper(ciphertext[i]))
            //{
            //    ciphertext[i] = (plaintext[i] + argv[2]) % 90;
            //}

        //}


}

