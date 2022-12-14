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

    //open memory card - fopen r
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    typedef uint8_t BYTE;

    BYTE buffer[512];

    int JPEG_count = 0;

    FILE *ptr = NULL;

    //loop until fread = 0 (EOF) & read 512 bytes into a buffer
    while (fread(buffer, sizeof(BYTE), 512, input) != 0)
    {
        //if start of new JPEG - JPEG header {0xff, 0xd8, 0xff} - plus four bits
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            JPEG_count++;
            //if first JPEG - open new file and write else close previous and open new file
            if (JPEG_count == 1)
            {
                char name[4];
                sprintf(name, "%03i.jpg", JPEG_count - 1);

                FILE *img = fopen(name, "w");
                ptr = img;
                if (img == NULL)
                {
                    printf("Could not open new file\n");
                    return 1;
                }

                fwrite(buffer, sizeof(BYTE), 512, img);
            }
            //if it's not the first JPEG then shut the previous file first
            if (JPEG_count > 1)
            {
                fclose(ptr);

                char name[4];
                sprintf(name, "%03i.jpg", JPEG_count - 1);

                FILE *img = fopen(name, "w");
                ptr = img;
                if (img == NULL)
                {
                    printf("Could not open new file\n");
                    return 1;
                }

                fwrite(buffer, sizeof(BYTE), 512, img);

            }
            //if the first JPEG has been found and 512 block does not inlcude JPEG header
            //then write the next block to the file
        }
        else if (JPEG_count >= 1)
        {
            fwrite(buffer, sizeof(BYTE), 512, ptr);
        }

    }
    // Close files
    fclose(input);
}


