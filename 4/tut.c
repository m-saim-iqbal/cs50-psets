#include <stdio.h>

// & = ampersand operator is used to tell the address of a variable

// * this is the dereference operator, how to get to the address of something

// %p = format specifier for pointers

// pointers are usually 64 bits, integers are 4 bits

// int n = 50;
// int *p = &n;
// printf("%p\n", &n); // address of n
// printf("%i\n", n);  // value of n
// printf("%p\n", p);  // address of n
// printf("%i\n", *p); // value of n using the dereference operator

int main()
{
    char *a = "Saim";

    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
    printf("%p\n", &a[2]);
    printf("%p\n\n", &a[3]);
    
    printf("%c\n", *a);
    printf("%c\n", *(a + 1));
    printf("%c\n", *(a + 2));
    printf("%c\n\n", *(a + 3));

    int x[] = {25, 50, 75, 100};

    printf("%p\n", &x[0]);
    printf("%p\n", &x[1]);
    printf("%p\n", &x[2]);
    printf("%p\n", &x[3]);
} 