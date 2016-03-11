#include <stdio.h>
int Decrescente(int *);
const int DIM=7;

int main(){
  int vet[DIM], i;

  for(i=0;i<DIM;i++){
    printf("Inserisci il valore del %d° elemento: ", i+1);
    scanf("%d", &vet[i]);
  }

  printf("Il vettore ");
  Decrescente(vet)==1? printf("è"): printf("non è");
  printf(" decrescente");
}

int Decrescente(int *p){
  int i, decrescente=1;
  for(i=1;i<DIM;i++){
    if(*(p+i-1)<*(p+i)){
      decrescente=0;
      break;
    }
  }
  return(decrescente);
}
