#include <stdio.h>
int RicercaVettoreNonOrdinato(int lista[], int n, int x, int *count);
int RicercaVettoreOrdinato(int lista[], int n, int x, int *count);
int RicercaBinaria(int lista[], int n, int x, int *count);
int DicotomicaRicorsiva(int a[], int x, int eINF, int eSUP);

int main(){
  int c, lista[10]={1,3,5,6,7,8,10,13,14,15}, count=0;//count serve per vedere quante volte viene eseguito il ciclo

  c=RicercaVettoreNonOrdinato(lista, 10, 13, &count);
  printf("%d, %d", c, count);

  count=0;
  c=RicercaVettoreOrdinato(lista, 10, 13, &count);
  printf("\n%d, %d", c, count);

  count=0;
  c=RicercaBinaria(lista, 10, 13, &count);
  printf("\n%d, %d", c, count);
}

int RicercaVettoreNonOrdinato(int lista[], int n, int x, int *count){
  int i;
  for(i=0;i<n;i++){
    *count=*count+1;
    if(lista[i]==x)
      return(i);
  }
  return(-1);
}

int RicercaVettoreOrdinato(int lista[], int n, int x, int *count){
  int i;
  for(i=0;i<n && lista[i]<=x;i++){
    *count=*count +1;
    if(lista[i]==x)
      return(i);
    }
  return(-1);
}

int RicercaBinaria(int lista[], int n, int x, int *count){
  int h=0, k=n-1, p;

  while(h <= k) {
    (*count)++;
    p = (h + k) / 2;
    if(lista[p] == x)
      return p;
    if(lista[p] < x)
      h = p + 1;
    else
      k = p - 1;
  }
  return(-1);
}

int DicotomicaRicorsiva(int a[], int x, int eINF, int eSUP){
  int pm=(eSUP+eINF)/2;
  if(eSUP<=eINF)
    return -1;
  else if(a[pm]==x)
    return pm;
  else if(a[pm]>x)
    return DicotomicaRicorsiva(a, x, eINF, pm-1);
  else
    return DicotomicaRicorsiva(a, x, pm+1, eSUP);
}
