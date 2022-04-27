#include "helpers.h"

int sepiaconvert(int tr, int tg, int tb, float r, float g, float b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float grey = ((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen)/3;
            image[i][j].rgbtRed = (int)grey;
            image[i][j].rgbtBlue = (int)grey;
            image[i][j].rgbtGreen = (int)grey;
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
    for (int i = 0; i < height, i++)
    {
        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// separate function to implement Sepia conversion
int sepiaconvert(int tr, int tg, int tb, float r, float g, float b)
{
    float sepiatone = r * tr + g * tg + b * tb;

    if (sepiatone > 255)
    {
        sepiatone = 255;
    }

    return (int) sepiatone;
}