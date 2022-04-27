#include "helpers.h"

void sepiaconvert(RGBTRIPLE input, int i, int j);

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
            image[i][j].rgbtRed = sepiatone(image[i][j], .393, .769, .189);
            image[i][j].rgbtGreen  = sepiatone(image[i][j], .349, .686, .168);
            image[i][j].rgbtBlue = sepiatone(image[i][j], .272, .534, .131);



            //original
            //float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            //float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            //float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            //if (sepiaRed > 255)
            //{
            //    image[i][j].rgbtRed = 255;
            //}
            //else
            //{
            //    image[i][j].rgbtRed = (int)sepiaRed;
            //}

            //if (sepiaBlue > 255)
            //{
            //    image[i][j].rgbtBlue = 255;
            //}
            //else
            //{
            //image[i][j].rgbtBlue = (int)sepiaBlue;
            //}

            //if (sepiaGreen > 255)
            //{
            //    image[i][j].rgbtGreen = 255;
            //}
            //else
            //{
            //    image[i][j].rgbtGreen = (int)sepiaGreen;
            //}
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// separate function to implement Sepia conversion
int sepiaconvert(RGBTRIPLE input, float r, float g, float b)
{
    float sepiatone = r * image[i][j].rgbtRed + g * image[i][j].rgbtGreen + b * image[i][j].rgbtBlue;

    if (sepiatone > 255)
    {
        sepiatone = 255;
    }

    return (int) sepiatone;
}