#include <stdio.h>
#include <stdio_ext.h>
#include "Esami.h"

int main(){
  Studente aula[AULA];
  Esame esame[ESAMI];

  InserisciAula(aula);
  InserisciEsami(esame, aula);
  Menu(aula, esame);

  __fpurge(stdin);
  getchar();

}
