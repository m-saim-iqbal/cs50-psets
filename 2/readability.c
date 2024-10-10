#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *input = NULL;
    size_t size = 0;
    int ch;
    
    printf("Enter a sentence: ");
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        input = realloc(input, size + 2);  // Dynamically increase size
        if (!input) {
            perror("Memory allocation failed");
            return 1;
        }
        input[size++] = ch;
    }
    input[size] = '\0';  // Null-terminate the string

    printf("\nThe sentence you entered is: %s\n", input);

    free(input);  // Free the dynamically allocated memory
    return 0;
}
