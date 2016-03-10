/**
Scrivere un programma in linguaggio C che riceve in ingresso una parola inserita da tastiera.
Si consideri che la parola può contenere sia caratteri maiuscoli che caratteri minuscoli,
e complessivamente al massimo 30 caratteri. Il programma deve svolgere le seguenti
operazioni:
    * visualizzare la parola inserita
    * aggiornare la parola in modo che tutti i caratteri siano minuscoli. Il programma deve
      visualizzare la parola ottenuta
    * verificare se la parola è palindroma. Una parola è palindroma se può essere letta
      indifferentemente da sinistra verso destra e da destra verso sinistra. Ad esempio, le
      seguenti parole sono palindrome: otto, madam.
**/
#include <stdio.h>
#include <ctype.h>
const int MAX=10;

int main(){
  int i, j, meta, palindroma=1;
  char str[MAX];

  printf("Inserisci una parola.\n");
  for(i=0;i<MAX-1 && (str[i]=getchar())!=' ' && str[i]!='\n';i++);
  str[i]='\0';

  printf("Hai scelto la parola: %s\n", str);
  for(i=0;(str[i]=tolower(str[i]))!='\0';i++);

  meta=--i/2;
  for(j=0;j<meta;j++){
    if(str[j]!=str[i-j]){
      palindroma=0;
      break;
    }
  }

  printf("la parola \"%s\" ", str);
  palindroma==1 ? printf("è palindroma."): printf("non è palindroma.");
}
