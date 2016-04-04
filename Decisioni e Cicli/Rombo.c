#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j, i, n, star, space;

    printf("Inserisci il numero della diagonale (dispari): ");
    scanf("%d", &n);

    star= 1;
    space= n/2;

    if (n%2 != 0){

        for(i=0; i<n; i++){

            for(j=0; j<space; j++)
                printf(" ");
            for(j=0; j<star; j++)
                printf("*");
            for(j=0; j<space; j++)
                printf(" ");

            printf("\n");

            if (i<n/2){
                star = star +2;
                space = space -1;
            }else{
                star = star -2;
                space = space +1;
            }
        }
    }else{
        printf("Il numero inserito non è valido");
    }
}
