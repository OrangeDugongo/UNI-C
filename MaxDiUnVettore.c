#include <stdio.h>
int Max(int *);
int Min(int *);
const int DIM=5;

int main(){
  int i, v[DIM];

  for(i=0;i<DIM;i++){
    printf("Inserisci il %d° intero: ", i+1);
    scanf("%d", &*(v+i));
  }

  printf("\nIl max è: %d\nIl min è: %d", Max(v), Min(v));
}

int Max(int *v){
  int i; int max=*v;
  for(i=1;i<DIM;i++){
    if(*(v+i)>max)
      max=*(v+i);
  }
  return(max);
}

int Min(int *v){
  int i; int min=*v;
  for(i=1;i<DIM;i++){
    if(*(v+i)<min)
      min=*(v+i);
  }
  return(min);
}
