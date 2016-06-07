/*
    Data una lista di almeno 2 elementi scrivere una funzione che la modifichi,
    in modo che l'ultimo elemento sia uguale al prodotto del penultimo e dell'
    ultimo.

    Esempio: data la lista 4-6-2-3-9 diventa 4-24-12-6-27
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <malloc.h>

typedef struct nodo{
  int valore;
  struct nodo *next;
}Nodo;

void Inserimento(Nodo **head, int n);
void Modifica(Nodo *head);

int main(){
  Nodo *head=NULL;
  int valore;
  FILE *src=fopen("base", "r");

  while(fscanf(src, "%d", &valore) != EOF)
    Inserimento(&head, valore);

  Modifica(head);

  while(head){
    printf("%3d ", head->valore);
    head=head->next;
  }

  __fpurge(stdin);
  getchar();
}

void Inserimento(Nodo **head, int n){
  Nodo *cur=*head, *pre=NULL;
  Nodo *New=(Nodo *)malloc(sizeof(Nodo));

  New->valore=n;

  while(cur){
    pre=cur;
    cur=cur->next;
  }

  if(!pre){
    New->next=*head;
    *head=New;
  }else{
    pre->next=New;
    New->next=cur;
  }
}

void Modifica(Nodo *head){
  Nodo *cur=head, *pre=NULL;
  int prodotto, prodottoP=cur->valore;

  while(cur){

    if(pre){
      prodotto=cur->valore*pre->valore;
      pre->valore=prodottoP;
      prodottoP=prodotto;
    }

    pre=cur;
    cur=cur->next;
  }

  pre->valore=prodottoP;
}
