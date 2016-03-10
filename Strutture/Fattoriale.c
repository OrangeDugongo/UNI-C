#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, fat;
    fat=1;

    printf("Inserisci il numero: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
        fat= fat*(n-i);

    printf("%d! = %d", n, fat);
}
