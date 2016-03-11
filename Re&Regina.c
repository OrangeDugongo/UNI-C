/**
Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
Si scriva un programma in linguaggio C che, acquisite le posizioni del Re e della Regina,
determini se la Regina è in posizione tale da poter mangiare il Re. Le posizioni dei due pezzi
sono identificate da mediante la riga e la colonna su cui si trovano, espresse come numeri
interi tra 1 e 8.
**/
#include <stdio.h>
void Posizione(char str[], int *, int *);
int RigaColonna(int, int, int, int);
int Diagonali(int, int, int, int);

int main(){
  int ReX, ReY, ReginaX, ReginaY;

  Posizione("del Re", &ReX, &ReY);
  do{
    Posizione("della Regina", &ReginaX, &ReginaY);
  }while(ReX==ReginaX && ReY==ReginaY);

  if(RigaColonna(ReX, ReY, ReginaX, ReginaY) || Diagonali(ReX, ReY, ReginaX, ReginaY))
    printf("La Reggina mangia il Re.");
  else
    printf("Il Re vive.");
}

void Posizione(char *str, int *px, int *py){
  do{
    printf("Inserisci la posizione %s(riga colonna): ", str);
    scanf("%d %d", &*py, &*px);
  }while(*px>8 || *px<0 || *py>8 || *py<0);
}

int RigaColonna(int rx, int ry, int rgx, int rgy){
  int mangia=0;
  if (rx==rgx||ry==rgy)
    mangia=1;
  return(mangia);
}

int Diagonali(int rx, int ry, int rgx, int rgy){
  int mangia=0;
  if((rx+ry==rgx+rgy) || (rx-ry==rgx-rgy))
    mangia=1;
  return(mangia);
}
