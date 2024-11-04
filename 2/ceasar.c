#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

char cypher(char, int);

int main(int argc, char **argv)
{

    char *input = NULL;
    size_t size = 0;
    int ch;

    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        int size_of_argv = sizeof(argv[1]);
        for (int i = 0; i < size_of_argv; i++)
        {
            if ((int)argv[1][i] == 0)
                break;
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./ceasar key");
                return 1;
            }
        }
        int key = atoi(argv[1]);
        printf("key: %d\n", key);

        printf("plaintext: ");

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

        printf("\nciphertext: ");
        for (int i = 0; i < size; i++)
        {
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
                printf("%c", cypher(input[i], key));
            else
                printf("%c", input[i]);
        }
    }
    else
    {
        printf("Usage: ./ceasar key");
        return 1;
    }
    free(input);
}

char cypher(char x, int key)
{
    if (x >= 'a' && x <= 'z')
    {
        x = x - 97;
    }
    else
    {
        x = x - 65;
    }
    x = x + key;
    x = x % 26;
    if (x >= 'a' && x <= 'z')
    {
        x = x + 97;
    }
    else
    {
        x = x + 65;
    }

    return x;
}

// Odds are you’ll want to subtract the ASCII value of 'A' from any uppercase letters, so as to treat 'A' as 0, 'B' as 1, and so forth, while performing arithmetic. And then add it back when done with the same.
// Odds are you’ll want to subtract the ASCII value of 'a' from any lowercase letters, so as to treat 'a' as 0, 'b' as 1, and so forth, while performing arithmetic. And then add it back when done with the same