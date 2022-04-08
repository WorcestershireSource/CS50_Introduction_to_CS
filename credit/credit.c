#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt user for card number
    long card;

    card = get_long("What is card number?\n");

    //create variables
    int length = 0;
    int comp = 0;
    long cardx = card;

    //determine card length
    if (card > 1e12 && card <= 1e13)
    {
        length = 13;
        comp = cardx / 1e11;
    }
    else if (card > 1e13 && card <= 1e14)
    {
        length = 14;
        comp = cardx / 1e12;
    }
    else if (card > 1e14 && card <= 1e15)
    {
        length = 15;
        comp = cardx / 1e13;
    }
    else if (card > 1e15 && card <= 1e16)
    {
        length = 16;
        comp = cardx / 1e14;
    }

    //decide which company 1 is visa, 2 is mastercard and 3 is amex, 4 is invalid
    int company;

    if (comp < 50 && comp > 39)
    {
        company = 1;
    }
    else if (comp < 56 && comp > 50)
    {
        company = 2;
    }
    else if (comp == 34 || comp == 37)
    {
        company = 3;
    }
    else
    {
        company = 4;
    }

    // luhn algorithm to check card accuracy
    //doubles every other figure, starting from second last, then adds digits (not products)
    //adds all other digits
    int x = 1;
    long fig = 0;

    while (x < 17)
    {
        if (x % 2 == 0 && (((card % 10) * 2) > 9))
        {
            fig += (((card % 10) * 2) % 10) + ((((card % 10) * 2) / 10) % 10);
        }
        else if (x % 2 > 0)
        {
            fig += (card % 10);
        }
        else
        {
            fig += (card % 10) * 2;
        }
        //before next cycle, card number altered so that next figure can be analysed
        card = card / 10;
        x++;
    }

    //check that figure is 10 factorial to determine validity
    long luhn = fig % 10;



    //amex 15 digit start 34 or 37
    // mastercard 16 digit start 51-55
    // visa 13 or 16 digits starts with 4

    //next section determines outcome and prints
    //printf last line should be amex, mc, visa, invalid
    if (luhn == 0 && company == 1 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if (luhn == 0 && company == 2 && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (luhn == 0 && company == 3 && length == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

}