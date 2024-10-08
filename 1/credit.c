#include <stdio.h>
#include <stdbool.h>

int main()
{
    long long int input = 0;
    char buffer[20];
    do
    {
        do
        {
            printf("Number: ");
            fgets(buffer, sizeof(buffer), stdin);
        } while (sscanf(buffer, "%lld", &input) != 1);
    } while (input < 0);

    long long int x = input;
    long long int x1 = x;
    long long int x2 = x;
    long long int x3 = x;
    char type_of_card;

    // luhn algorithm
    int counter = 0;
    int counter1 = 0;
    int product_sum = 0;
    int total = 0;
    while (x2 != 0)
    {
        int t = x2 % 10;
        x2 = x2 / 10;
        if (counter == 0)
        {
            counter++;
            continue;
        }
        else if (counter % 2 == 0)
        {
            counter++;
            continue;
        }
        int t_prod = t * 2;
        while (t_prod != 0)
        {
            int t2 = (t_prod) % 10;
            t_prod = t_prod / 10;
            product_sum = product_sum + (t2);
        }
        counter++;
    }
    while (x3 != 0)
    {
        int t = x3 % 10;
        x3 = x3 / 10;

        if (counter1 % 2 != 0)
        {
            counter1++;
            continue;
        }
        total = total + t;
        counter1++;
    }

    if ((total + product_sum) % 10 == 0)
    {
        long long int first = x;
        long long int second = x;
        while (first >= 10)
        {
            first = first / 10;
        }
        while (second >= 100)
        {
            second = second / 10;
        }
        // printf("first: %d", first);
        second = second % 10;
        if (first == 4)
        {
            printf("VISA\n");
        }
        else if (first == 3 && (second == 4 || second == 7))
        {
            printf("AMEX\n");
        }
        else if (first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5))
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}