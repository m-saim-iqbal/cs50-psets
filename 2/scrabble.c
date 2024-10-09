#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculate_score(char str[], int size);

int main(void)
{
    char player1[20];
    char player2[20];
    printf("Player 1: ");
    scanf("%[^\n]%*c", player1);
    printf("Player 2: ");
    scanf("%[^\n]%*c", player2);

    printf("Player 1: %s", player1);
    printf("Player 2: %s", player2);
    int n = calculate_score(player1, 20);
    printf("player 1 score: %d", n);
}

int calculate_score(char str[], int size)
{
    int score = 0;
    for (int i = 0; i < size; i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'l' || str[i] == 'n' || str[i] == 'o' || str[i] == 'r' || str[i] == 's' || str[i] == 't' || str[i] == 'u' || str[i] == 'a') {
            score++;
        }
    }

    return score;
}