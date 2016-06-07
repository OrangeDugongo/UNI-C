/**
Data una matrice di dimensione uguale a 10 righe per 10 colonne contenente elementi
reali, scrivere un programma in linguaggio C per individuare se esistono righe o colonne
composte solo da elementi negativi.
**/
#include <stdio.h>
#include <math.h>
#include <time.h>
#define DIM 10
int Riga(int mat[DIM][DIM]);
int Colonna(int mat[DIM][DIM]);

int main(){
  int i, j, mat[DIM][DIM];

  srand(time(NULL));

  for(i=0;i<DIM;i++){
    for(j=0;j<DIM;j++)
      printf("%3d", (mat[i][j]=rand()%10*pow(-1,rand()%2)));
    printf("\n");
  }
  if(Riga(mat)||Colonna(mat))
    printf("\nLa matrice presenta una riga o una colonna tutta negativa");
  else
    printf("\nLa matrice non presenta righe o colonne tutte negative");
}

int Riga(int mat[DIM][DIM]){
  int i, j, count, negativa=0;
  for(i=0;i<DIM;i++){
    for(j=0;j<DIM;j++){
      if(mat[i][j]<0)
        count++;
    }
    if(count==10){
      negativa=1;
      break;
    }
    count=0;
  }
  return(negativa);
}

int Colonna(int mat[DIM][DIM]){
  int i, j, count, negativa=0;
  for(j=0;j<DIM;j++){
    for(i=0;i<DIM;i++){
      if(mat[i][j]<0)
        count++;
    }
    if(count==10){
      negativa=1;
      break;
    }
    count=0;
  }
  return(negativa);
}
