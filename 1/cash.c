#include <stdio.h>

int main()
{
    int input = 0;
    char buffer[10];
    int no_of_coins = 0;
    do
    {
        do
        {
            printf("Cash Owned: ");
            fgets(buffer, sizeof(buffer), stdin);
        } while (sscanf(buffer, "%d", &input) != 1);
    } while (input < 0);

    while (input != 0)
    {
        if (input >= 25)
        {
            input = input - 25;
            no_of_coins++;
        }
        else if (input >= 10)
        {
            input = input - 10;
            no_of_coins++;
        }
        else if (input >= 5)
        {
            input = input - 5;
            no_of_coins++;
        }
        else
        {
            input = input - 1;
            no_of_coins++;
        }
    }
    printf("%d", no_of_coins);
}