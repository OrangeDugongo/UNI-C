/**
Inserisci delle parole e le stampa usando la lista
**/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
int i=1;

struct lista{
  char *stringa;
  struct lista *next;
};
typedef struct lista Lista;
void Inserisci(struct lista **root);
void Stampa(struct lista *l);

int main(){
  int menu;
  Lista *root=NULL;
  do{
    printf("1. Inserisci\n");
    printf("2. Stampa: ");
    scanf("%d", &menu);

    switch(menu){
      case 1: Inserisci(&root);
        break;
      case 2: Stampa(root);
        break;
    }
  }while(menu);
}

void Inserisci(struct lista **root){
  char buffer[200];
  struct lista *l;
  scanf("%s", buffer);
  l=(struct lista*)malloc(sizeof(Lista));
  l->stringa=(char *)calloc(strlen(buffer)+1, sizeof(char));
  strcpy(l->stringa, buffer);
  l->next=*root;
  *root=l;
}

void Stampa(struct lista *root){
  struct lista* l=root;
  while(l!=NULL){
     printf("%s --> ", l->stringa);
     l=l->next;
  }
  printf(" FINE\n");
}
