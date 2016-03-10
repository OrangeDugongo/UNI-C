/**
Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La
frase è terminata dall’introduzione del carattere di invio. La frase contiene sia caratteri
maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma
deve svolgere le seguenti operazioni:
    * visualizzare la frase inserita.
    * costruire una nuova frase in cui il primo carattere di ciascuna parola nella frase di
      partenza è stato reso maiuscolo. Tutti gli altri caratteri devono essere resi minuscoli.
      Il programma deve memorizzare la nuova frase in una opportuna variabile.
    * visualizzare la nuova frase.
**/
#include <stdio.h>
#include <ctype.h>
void ToLower(char *, char *);
void Iniziali(char *);
const int MAX=100;

int main(){
  char str[MAX], stringa[MAX];
  int i;

  printf("Inserisci la frase.\n");

  for(i=0;i<MAX-1 && (str[i]=getchar())!='\n';i++);
  str[i]='\0';

  ToLower(str, stringa);
  stringa[0]=toupper(stringa[0]);
  Iniziali(stringa);

  printf("La stringa \"%s\" diventa: \"%s\"", str, stringa);
}

void ToLower(char *l, char *s){
  int i;
  for(i=0;(*(s+i)=tolower(*(l+i)))!='\0';i++);
}

void Iniziali(char *s){
  int i;
  for(i=0;*(s+i)!='\0';){
    if(*(s+i++)==' ')
      *(s+i)=toupper(*(s+i));
  }
}
