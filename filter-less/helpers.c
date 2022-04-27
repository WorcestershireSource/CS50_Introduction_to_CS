#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>

int sepiaconvert(int tr, int tg, int tb, float r, float g, float b);

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int temp_red = image[i][j].rgbtRed;
            int temp_green = image[i][j].rgbtGreen;
            int temp_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = sepiaconvert(temp_red, temp_green, temp_blue, .393, .769, .189);
            image[i][j].rgbtGreen  = sepiaconvert(temp_red, temp_green, temp_blue, .349, .686, .168);
            image[i][j].rgbtBlue = sepiaconvert(temp_red, temp_green, temp_blue, .272, .534, .131);
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

// separate function to implement Sepia conversion
//takes the raw RGB values and the adjustment for each as inputs
//checks if the result exceeds 255 max value
int sepiaconvert(int tr, int tg, int tb, float r, float g, float b)
{
    float sepiatone = r * tr + g * tg + b * tb;

    if (sepiatone > 255)
    {
        sepiatone = 255;
    }

    return round(sepiatone);
}