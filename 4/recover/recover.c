#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK_SIZE 512
 
int main(int argc, char *argv[])
{
	FILE *filePtr = NULL;

	if (argc == 2){
	 filePtr = fopen(argv[1], "rb");
	} else {
		printf("Usage: ./volume <inputfile>");
		return 1;
	}

	if (filePtr == NULL) {
		printf("Unable to open the file");
		return 1;
	}

 	uint8_t imgArr[CHUNK_SIZE];
    int counter = 0;
    int imageFound = 0;
    size_t bytesRead = 0;
    char filename[8];  // To store "###.jpg"
    FILE *img = NULL;

    while ((bytesRead = fread(imgArr, 1, CHUNK_SIZE, filePtr)) > 0) {
        // Check if the start of a JPEG file is detected
        if (imgArr[0] == 0xFF && imgArr[1] == 0xD8 && imgArr[2] == 0xFF && (imgArr[3] & 0xF0) == 0xE0) {
            if (img != NULL) {
                fclose(img);
            }
            // Create new filename
            sprintf(filename, "%03i.jpg", imageFound++);
            img = fopen(filename, "wb");
        }

        // Write to the currently open image file (if one exists)
        if (img != NULL) {
            fwrite(imgArr, 1, bytesRead, img);
        }
    }

    // Close any open files
    fclose(filePtr);
    if (img != NULL) {
        fclose(img);
    }

    printf("Images found: %d\n", imageFound);
    return 0;
}

