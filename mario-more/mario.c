#include <stdio.h>
#include <cs50.h>

void pyramidprint(void);
int counter = 1;

int main(void)
{
    //Prompt user for int
    int height;
    do
    {
        height = get_int("What is the size of the pyramid? 1 to 8\n");
    }
    while (height < 1 || height > 8);

    //create variables to control pyramid size
    int heightcount = height;

    //Loop for as many times as pyramid is tall
    for (int h = 0; h < height; h++)
    {
        //print spaces - loop for height - 1 times on first row and then decrease on each row
        for (int g = 1; g < heightcount; g++)
        {
            printf(" ");
        }

        //print hashes / spaces / hashes
        pyramidprint();

        printf("  ");

        pyramidprint();

        //new line and change variables for next iteration
        printf("\n");
        counter++;
        heightcount--;
    }
}


//New function to print pyramid blocks
void pyramidprint(void)
{
    for (int w = 0; w < counter; w++)
    {
        printf("#");
    }
}







