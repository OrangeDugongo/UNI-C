/*
Scrivere un programma che riceve in input una linea di caratteri e restituisce
una lista in cui i nodi indicano ciascuno il numero delle occorenze di ciascuno
dei caratteri presenti nella linea di input.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio_ext.h>

typedef struct Nodo{
  char c;
  int n;
  struct Nodo *next;
} Nodo;

typedef Nodo* NodoSTAR;

void Inserimento(char, NodoSTAR *);
void Print(NodoSTAR);

int main(){
  char buffer[200];
  unsigned int i;
  NodoSTAR head=NULL;
  printf("Inserisci una frase: ");
  gets(buffer);
  for(i=0;i<strlen(buffer);i++)
    if(isalpha(buffer[i]))
      Inserimento(buffer[i], &head);

  Print(head);
  __fpurge(stdin);
  getchar();
}

void Inserimento(char c, NodoSTAR *head){
  NodoSTAR cur=*head, pre=NULL;
  while(cur && c>cur->c){
    pre=cur;
    cur=cur->next;
  }
  if(cur && c==cur->c)
    (cur->n)++;
  else{
    NodoSTAR New=(NodoSTAR)malloc(sizeof(Nodo));
    New->c=c;
    New->n=1;
    if(!pre){
      New->next=*head;
      *head=New;
    }else{
      New->next=cur;
      pre->next=New;
    }
  }
}

void Print(NodoSTAR head){
  while(head){
    printf("%c=%d volte.\n", head->c, head->n);
    head=head->next;
  }
}
