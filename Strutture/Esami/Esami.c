#include <stdio.h>
#include <stdio_ext.h>
#include "Esami.h"

int main(){
  Studente aula[AULA];
  Esame esame[ESAMI];
  int continua;

  InserisciAula(aula);
  InserisciEsami(esame, aula);
  do{
    Menu(aula, esame);
    printf("0 per interrompere: ");
    scanf("%d", &continua);
  }while(continua);


  __fpurge(stdin);
  getchar();

}
