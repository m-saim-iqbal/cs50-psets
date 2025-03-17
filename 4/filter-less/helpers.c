#include "helpers.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
//#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	// itererating over the height/rows of the image
	for(int i = 0; i < height; i++){
		//iterating over the width/columns (each pixel) of the image
		for(int j = 0; j < width; j++) {
			 uint8_t blue = image[i][j].rgbtBlue;
			 uint8_t green = image[i][j].rgbtGreen;
			 uint8_t red = image[i][j].rgbtRed;

			 uint8_t average = (blue + green + red) / 3 ;
			 //printf("the average of the first pixel is: %u\n", average);
			 image[i][j].rgbtBlue = average;
			 image[i][j].rgbtGreen = average;
			 image[i][j].rgbtRed = average;
		}
	}
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{	
	// itererating over the height/rows of the image
	for(int i = 0; i < height; i++){
		//iterating over the width/columns (each pixel) of the image
		for(int j = 0; j < width; j++) {
			 uint8_t blue = image[i][j].rgbtBlue;
			 uint8_t green = image[i][j].rgbtGreen;
			 uint8_t red = image[i][j].rgbtRed;

			 uint8_t sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue) > 255 ? 255 : round(0.272 * red + 0.534 * green + 0.131 * blue);
			 uint8_t sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue) > 255 ? 255 : round(0.349 * red + 0.686 * green + 0.168 * blue);
			 uint8_t sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue) > 255 ? 255 : round(0.393 * red + 0.769 * green + 0.189 * blue);

			 //printf("the average of the first pixel is: %u\n", average);
			 image[i][j].rgbtBlue = sepiaBlue;
			 image[i][j].rgbtGreen = sepiaGreen;
			 image[i][j].rgbtRed = sepiaRed;
		}
	}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	// itererating over the height/rows of the image
	for(int i = 0; i < height; i++){
		//iterating over the width/columns (each pixel)
		for(int j = 0; j < width / 2; j++) {
			 RGBTRIPLE temp = image[i][j];
			 image[i][j] = image[i][width - j - 1];
			 image[i][width - j - 1] = temp;
		}
	}

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// itererating over the height/rows of the image
	for(int i = 0; i < height; i++){
		//iterating over the width/columns (each pixel)
		for(int j = 0; j < width; j++) {
			//RGBTRIPLE grid1 = image[i-1][j-1];
			//RGBTRIPLE grid2 = image[i-1][j];
			//RGBTRIPLE grid3 = image[i-1][j+1];
			//RGBTRIPLE grid4 = image[i][j-1];
			//RGBTRIPLE grid5 = image[i][j];
			//RGBTRIPLE grid6 = image[i][j+1];
			//RGBTRIPLE grid7 = image[i+1][j-1];
			//RGBTRIPLE grid8 = image[i+1][j];
			//RGBTRIPLE grid9 = image[i+1][j+1];

			int averageBlue = 0;
			int averageGreen = 0;
			int averageRed = 0;
			int counter = 0;
			for(int a = -1; a <= 1; a++) {
				// first i will write the condition to handle the edge cases for (i) which is the height
				if( i == 0 && a == -1) {
					continue;
				} else if ( i == (height -1) && a == 1) {
					continue;
				}
				for(int b = -1; b <= 1; b++) {
					// i will write the condition to handle the edge cases for (j) whichj is the width
					if ( j == 0 && b == -1) {
						continue;
					} else if (j == (width -1) && b == 1) {
						continue;
					}
					averageBlue += image[i+a][j+b].rgbtBlue;
					averageGreen += image[i+a][j+b].rgbtGreen;
					averageRed += image[i+a][j+b].rgbtRed;
					counter++;
				}
			}
			image[i][j].rgbtBlue = round(averageBlue / counter);
			image[i][j].rgbtGreen = round(averageGreen / counter);
			image[i][j].rgbtRed = round(averageRed / counter);
		}
	}
    return;
}
