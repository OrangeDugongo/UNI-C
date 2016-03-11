/**
Leggere un insieme di numeri, inserirlo in un array e
calcolare la media. L’utente dovrà
esplicitamente indicare quanti numeri vuole inserire
nell’array.
**/
#include <stdio.h>
const int DIMAX = 15;

int main(){
  int sum, i, n, vet[DIMAX];
  do{
    printf("Quanti interi vuoi inserire: ");
    scanf("%d", &n);
  } while (n>DIMAX);

  for(i=0;i<n;i++){
    printf("Inserisci il valore del %d° intero: ", i+1);
    scanf("%d", &vet[i]);
  }

  for(i=0;i<n;i++)
    sum+=vet[i];

  printf("La media vale %d", sum/n);
}
