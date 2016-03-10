#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Min(int a[]);
int Max(int a[]);
void Print(int a[]);
const int DIM = 5;

int main(){
    int diagPrin[DIM], diagSec[DIM], mat[DIM][DIM];
    int i, j;

    srand(time(NULL));

    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            mat[i][j]=rand()%10*pow(-1, rand()%2);
            printf(" %2d", mat[i][j]);
            }
        printf("\n");
    }

    printf("\n");

     for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(i==j)
                diagPrin[i]=mat[i][j];
            if(i+j==DIM-1)
                diagSec[i]=mat[i][j];
        }
    }


    printf("Diagonale principale: ");
    Print(diagPrin);
    printf("Diagonale secondaria: ");
    Print(diagSec);

    printf("Diagonale principale: Max=%d, min=%d\n", Max(diagPrin), Min(diagPrin));
    printf("Diagonale secondaria: Max=%d, min=%d\n", Max(diagSec), Min(diagSec));
}

int Max(int a[]){
    int max=a[0], i;
    for(i=0;i<DIM;i++){
        if(a[i]>max)
            max=a[i];
    }
    return(max);
}

int Min(int a[]){
    int min=a[0], i;
    for(i=0;i<DIM;i++){
        if(a[i]<min)
            min=a[i];
    }
    return(min);
}

void Print(int a[]){
    int i;
    for(i=0;i<DIM;i++)
        printf("%d ", a[i]);
    printf("\n");
}
