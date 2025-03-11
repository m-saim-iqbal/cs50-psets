#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *  j = 0;
    char *i = 0;

    j = scanf("Enter an integer: ");
    i = scanf("Enter another integer: ");

    if (i == j)
    {
        printf("Both are equal");
    }
    else
    {
        printf("Un equal");
    }
}