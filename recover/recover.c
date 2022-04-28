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

FILE *output = fopen(argv[2], "w");
if (output == NULL)
{
    printf("Could not open new file.\n");
    return 1;
}

//check for 0xff 0xd8 0xff at first three bytes followed by byte beginning with 0xe? (1110)

// check three bytes, check first half of fourth
// take 512 bytes, including four checked (4 + 508)
// if JPEG, write to new output file
// repeat

//stores the generic JPEG header first three bytes
uint8_t header[] = {0xff, 0xd8, 0xff};

//performs the checks and stores the fourth JPEG byte
uint8_t copy;

//stores the main JPEG file
uint8_t body[508];

while(fread(&copy, sizeof(uint8_t), 1, input))
{
    if (copy == 0xff)
    {
        fread(&copy, sizeof(uint8_t), 1, input);
        if (copy == 0xd8)
        {
            fread(&copy, sizeof(uint8_t), 1, input);
            if (copy == 0xff)
            {
                fread(&copy, sizeof(uint8_t), 1, input);
                if (copy >= 0xe0 && copy <= 0xef)
                {
                    fwrite(&header, sizeof(uint8_t), 1, output);
                    fwrite(&copy, sizeof(uint8_t), 1, output);

                    fread(&body, 508, 1, output);
                    fwrite(&body, 508, 1, output);
                }
            }
        }
    }
}

    // Close files
    fclose(input);
    fclose(output);

}