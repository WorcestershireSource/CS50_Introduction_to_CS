#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

if (argc != 2)
{
    printf("Usage ./recover filename\n");
    return 1;
}

FILE *input = fopen(argv[1], "r");
if (input == NULL)
{
    printf("Could not open file.\n");
    return 1;
}

//FILE *output = fopen(argv[2], "w");
//if (output == NULL)
//{
//    printf("Could not open new file.\n");
//    return 1;
//}

//check for 0xff 0xd8 0xff at first three bytes followed by byte beginning with 0xe? (1110)

// check three bytes, check first half of fourth
// take 512 bytes, including four checked (4 + 508)
// if JPEG, write to new output file
// repeat

//stores the generic JPEG header first three bytes
uint8_t header[] = {0xff, 0xd8, 0xff};

//performs the checks and stores the fourth JPEG byte
uint8_t *copy = malloc(sizeof(uint8_t) * 512);

while(fread(&copy, 1, 512, input) == 512)
{

}

    // Close files
    fclose(input);
//    fclose(output);


//dynamic memory allocation deals with unknown file size

}