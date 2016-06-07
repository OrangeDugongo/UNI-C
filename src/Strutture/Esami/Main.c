#include <stdio_ext.h>
#include "Esami.h"

int main(){
  Studente aula[AULA];
  Esame esame[ESAMI];
  int menu;

  InserisciAula(aula);
  InserisciEsami(esame, aula);
  do{
    printf("Inserisci 1 per avere una panoramica della classe\n2 per cercare un singolo studente\n0 per terminare: ");
    scanf("%d", &menu);
    Menu(aula, esame, menu);
    if(menu)
      printf("\n-------------\n\n");
  }while(menu);

  __fpurge(stdin);
  getchar();

}
