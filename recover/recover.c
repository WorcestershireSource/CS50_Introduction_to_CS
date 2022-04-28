#include <stdio.h>
#include <stdlib.h>

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

FILE *output = fopen(argv[2], "w");
if (output == NULL)
{
    printf("Could not open file.\n");
    return 1;
}

//check for 0xff 0xd8 0xff at first three bytes followed by byte beginning with 0xe? (1110)

// check three bytes, check first half of fourth
// take 512 bytes, including four checked (4 + 508)
// if JPEG, write to new output file
// repeat

int8_t copy;

while(fread(copy, sizeof(uint8_t), 1, input))
{
    if (copy == 0xff)
    {
        fread(copy, sizeof(uint8_t), 1, input)
        if 
    }
}

}