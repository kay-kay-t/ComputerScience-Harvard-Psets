#include "helpers.h"
#include <cs50.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // where i is a raw
    for (int i = 0; i < height; i++)
    {
        // where j is a column
        for (int j = 0; j < width; j++)
        {
        // get values of each color and devide it by 3 to find avarage
        float red = image[i][j].rgbtRed;
        float blue = image[i][j].rgbtBlue;
        float green = image[i][j].rgbtGreen;

        float average = round((red + blue + green) / 3);

        image[i][j].rgbtRed = average;
        image[i][j].rgbtBlue = average;
        image[i][j].rgbtGreen = average;
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
         int red = image[i][j].rgbtRed;
         int blue = image[i][j].rgbtBlue;
         int green = image[i][j].rgbtGreen;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
             if (sepiaRed < 256)
             {
                 image[i][j].rgbtRed = sepiaRed;
             }
             else
             {
                 image[i][j].rgbtRed = 255;
             }
             if (sepiaGreen < 256)
             {
                 image[i][j].rgbtGreen = sepiaGreen;
             }
             else
             {
                 image[i][j].rgbtGreen = 255;
             }
             if (sepiaBlue < 256)
             {
                image[i][j].rgbtBlue = sepiaBlue;
             }
             else
             {
                 image[i][j].rgbtBlue = 255;
             }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int m = (width - 1 - j);
            newimage[i][m] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // place the newly flipped values into the old array
            image[i][j] = newimage[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   // create a copy of array to new image to blur
   RGBTRIPLE newImage[height][width];

   for (int i = 0; i < height; i++)
   {
        for (int j = 0; j < width; j++)
       {
            newImage[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // putting those values up here, so for loop recognize them (initializing pixel_count)
            int pixel_count = 0;
            float sumr = 0;
            float sumg = 0;
            float sumb = 0;
            // checking each pixel within -1 and +1 in a raw [i] aka left to right (height)
            for (int k = -1; k < 2; k++)
            {
                // cheking each pixel within -1 and +1 in a column [j] aka up to down (width)
                for (int l = -1; l < 2; l++)
                {
                    // cheking if there is pixel around 
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                    {
                        sumr = newImage[i + k][j + l].rgbtRed + sumr;
                        sumg = newImage[i + k][j + l].rgbtGreen + sumg;
                        sumb = newImage[i + k][j + l].rgbtBlue + sumb;
                        //counting how many pixels are around
                        pixel_count++; 
                        
                    }
                }
            }
            image[i][j].rgbtRed = round(sumr / pixel_count);
            image[i][j].rgbtGreen = round(sumg / pixel_count);
            image[i][j].rgbtBlue = round(sumb / pixel_count);
        }
    }
    return;
}
