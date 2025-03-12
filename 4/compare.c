#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *a = "hi!";
    char *b = malloc(strlen(a) + 1);
    
    if (b == NULL) {
    	return 1;
    }    

    for(int i = 0, n = strlen(a); i < n; i++) {
		b[i] = a[i];
    }

    printf("a: %s\n", a);
    printf("b: %s\n", b);

	free(b);	
}
