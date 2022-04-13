#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2 || isalpha(argv[2]) != 0 || argv[2] < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext:  ");

        int l = strlen(plaintext);

        string ciphertext;

        //for(int i = 0; i < l; i++)
        //{
            //if(islower(ciphertext[i]))
            ///{
                int x = ((int) plaintext[0] + (int) argv[2]) % 122;
                printf("%i\n", x);
                printf("%i\n", (int) argv[1]);
                //ciphertext[i] = (string) x;
            //}
            //if(isupper(ciphertext[i]))
            //{
            //    ciphertext[i] = (plaintext[i] + argv[2]) % 90;
            //}

        //}

    }

}