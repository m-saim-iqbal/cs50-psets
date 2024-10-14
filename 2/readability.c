#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float indexCalculator(char string[], int size);

int main(int argc, char **argv)
{
    char *input = NULL;
    size_t size = 0;
    int ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        input = realloc(input, size + 2); // Dynamically increase size
        if (!input)
        {
            perror("Memory allocation failed");
            return 1;
        }
        input[size++] = ch;
    }
    input[size] = '\0'; // Null-terminate the string

    float x = indexCalculator(input, size);
    printf("Index is: %f\n", x);

    

    free(input); // Free the dynamically allocated memory
    return 0;
}

//Coleman Liau Index formula: 5.89 x (characters/words) – 0.3 x (sentences/words) – 15.8
float indexCalculator(char string[], int size)
{
    float no_of_characters = 0;
    float no_of_words = 1;
    float no_of_sentences = 0;
    for(int i = 0; i < size; i++) {
        string[i] = tolower(string[i]);
        if(string[i] == ' ') {
            no_of_words++;
        }
        if(string[i] == '.' || string[i] == '!' || string[i] == '?') {
            no_of_sentences++;
        }
        if(string[i] >= 'a' && string[i] <= 'z') {
            no_of_characters++;
        }
    }
    printf("Total number of characters are: %f\n", no_of_characters);
    printf("Total number of words are: %f\n", no_of_words);
    printf("Total number of sentences are: %f\n", no_of_sentences);
    float index = 0.0588 * (100 * no_of_characters / no_of_words) - 0.296 * (100 * no_of_sentences / no_of_words) - 15.8;
    return index;
}
