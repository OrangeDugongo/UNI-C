#include <stdio.h>
#include <stdlib.h>
#define A 4
#define B 2
#define C 4
int Prodotto(int, int);
void Riempimento(int *, int, int);
int matrice[A][B], matrice2[B][C];

int main()
{
    int i, j;
    srand(time(NULL));

    Riempimento(matrice, A, B);
    Riempimento(matrice2, B, C);

    for(i=0;i<A;i++){
        for(j=0;j<C;j++)
            printf(" %4d", Prodotto(i, j));
        printf("\n");
    }
}

void Riempimento(int *mat, int x, int y){
    int i;
    for(i=0;i<x*y;i++)
        *(mat+i)=rand()%10*pow(-1,rand()%2);
}

int Prodotto(int i, int j){
    int prodotto=0, r;
    for(r=0;r<B;r++)
       prodotto+=matrice[i][r]*matrice2[r][j];
    return(prodotto);
}
