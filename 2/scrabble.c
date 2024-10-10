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

    int n = calculate_score(player1, 20);
    int n2 = calculate_score(player2, 20);
    printf("%d  %d", n, n2);

    if (n == n2)
    {
        printf("Tie!\n");
    }
    else if (n > n2)
    {
        printf("PLayer 1 Wins!\n");
    }
    else
    {
        printf("Player 2 Wins!\n");
    }
}

int calculate_score(char str[], int size)
{
    int score = 0;
    for (int i = 0; i < size; i++)
    {
        if ((int)str[i] == 0)
        {
            break;
        }
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'l' || str[i] == 'n' || str[i] == 'o' || str[i] == 'r' || str[i] == 's' || str[i] == 't' || str[i] == 'u')
        {
            score++;
        }
        else if (str[i] == 'd' || str[i] == 'g')
        {
            score = score + 2;
        }
        else if (str[i] == 'b' || str[i] == 'c' || str[i] == 'm' || str[i] == 'p')
        {
            score = score + 3;
        }
        else if (str[i] == 'f' || str[i] == 'h' || str[i] == 'w' || str[i] == 'v' || str[i] == 'y')
        {
            score = score + 4;
        }
        else if (str[i] == 'k')
        {
            score = score + 5;
        }
        else if (str[i] == 'j' || str[i] == 'x')
        {
            score = score + 8;
        }
        else if (str[i] == 'q' || str[i] == 'z')
        {
            score = score + 10;
        }
        else
        {
            continue;
        }
    }

    return score;
}