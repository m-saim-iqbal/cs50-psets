#include <stdio.h>

int main() {
    int input = 0;
    int temp = 0;
    char buffer[10];
    do {
        do {
            printf("Height: ");
            fgets( buffer, sizeof(buffer), stdin );
        } while ( sscanf( buffer, "%d", &input ) != 1 );
    } while(input < 0 || input > 8);
    temp = input;
    for(int i = 1;i <= input; i++){
        for(int j = temp;j>1;j--){
            printf(" ");
        }
        for(int m = 0;m<i;m++){
            printf("#");
        }
        printf("\n");
        temp--;
    }
}
