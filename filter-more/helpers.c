#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>

int sopel(int gx, int gy);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float grey = ((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen)/3;
            image[i][j].rgbtRed = round(grey);
            image[i][j].rgbtBlue = round(grey);
            image[i][j].rgbtGreen = round(grey);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int c = (width/2) - 1;

    RGBTRIPLE copy[height][width];

    //copy image to read from while blurring
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //temporarily remembers the first value so it can be overwritten
            //overwrites values
            image[i][j] = copy[i][width - (j + 1)];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    //copy image to read from while blurring
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //loop over all pixels to blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //average surrounding cells
            int avRed = 0;
            int avGreen = 0;
            int avBlue = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r >= 0 && i + r < height && j + c >= 0 && j + c < width)
                    {
                        avRed = avRed + copy[i + r][j + c].rgbtRed;
                        avGreen = avGreen + copy[i + r][j + c].rgbtGreen;
                        avBlue = avBlue + copy[i + r][j + c].rgbtBlue;
                    }

                }
            }

            //check if it is an edge or corner
            int cells = 6;
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1))
            {
                cells = 4;
            }
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                cells = 9;
            }

            avRed = round((float) avRed / cells);
            avGreen = round((float) avGreen / cells);
            avBlue = round((float) avBlue / cells);

            image[i][j].rgbtRed = avRed;
            image[i][j].rgbtGreen = avGreen;
            image[i][j].rgbtBlue = avBlue;
        }
    }
    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    //copy image to read from while blurring
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //initialise kernals for sopel calculation
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    //loop over all pixels

    //CHANGED TO THREE PIXEL SQUARE
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int trx = 0;
            int tgx = 0;
            int tbx = 0;
            int try = 0;
            int tgy = 0;
            int tby = 0;

            //loop over surrounding cells
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    trx = trx + copy[i + r][j + c].rgbtRed * Gx[r + 1][c + 1];
                    tgx = tgx + copy[i + r][j + c].rgbtGreen * Gx[r + 1][c + 1];
                    tbx = tbx + copy[i + r][j + c].rgbtBlue * Gx[r + 1][c + 1];

                    try = try + copy[i + r][j + c].rgbtRed * Gy[r + 1][c + 1];
                    tgy = tgy + copy[i + r][j + c].rgbtGreen * Gy[r + 1][c + 1];
                    tby = tby + copy[i + r][j + c].rgbtBlue * Gy[r + 1][c + 1];
                }
            }
        image[i][j].rgbtRed = sopel(trx, try);
        image[i][j].rgbtGreen = sopel(tgx, tgy);
        image[i][j].rgbtBlue = sopel(tgx, tgy);
        }
    }
    //add border management (assume black border)

    return;
}

int sopel(int gx, int gy)
{
    int outcome = sqrt(pow(((float) gx, 2) + pow((float) gy, 2));

    if (outcome > 255)
    {
        return 255;
    }

    return round(outcome);
}

