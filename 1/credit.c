#include <stdio.h>

int main(){
    long long int x = 4003600000000014;
    int lenghtX;
    // printf("%d", sizeof(x));
    while (x != 0) {
        int t = x % 10;
        x = x/ 10;
        lenghtX++;
    }
    printf("%d", lenghtX);
}