#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdio_ext.h>

typedef struct Token{
  char *stringa;
  int n;
  struct Token *next;
} Token;

void Print(Token *, FILE *);
int Trovato(Token *, char *);
void Inserisci(Token **head, char *buffer);

int main(){
  FILE *fp;
  Token *head=NULL;
  char buffer[200];

  printf("Che file vuoi caricare: ");
  scanf("%s", buffer);
  if((fp=fopen(buffer, "r"))){
    while(fscanf(fp, "%s", buffer)!=EOF)
      if(!Trovato(head, buffer))
        Inserisci(&head, buffer);
      Print(head, NULL);
  }else
    printf("Impossibile aprire il file.");

  __fpurge(stdin);
  getchar();
}

int Trovato(Token *head, char *buffer){
  int trovato=0;
  while(head && !trovato){
    if(!strcmp(buffer, head->stringa)){
      (head->n)++;
      trovato=1;
    }
      head=head->next;
  }
  return(trovato);
}

void Inserisci(Token **head, char *buffer){
  Token *New, *cur=*head, *pre=NULL;
  New=(Token *)malloc(sizeof(Token));
  New->stringa=(char *)calloc(strlen(buffer)+1, sizeof(char));
  strcpy(New->stringa, buffer);
  New->n=1;
  if(!cur || strcmp(buffer, cur->stringa)<0){
    New->next=*head;
    *head=New;
  }else{
    while(cur && strcmp(buffer, cur->stringa)>0){
      pre=cur;
      cur=cur->next;
    }
    pre->next=New;
    New->next=cur;
  }
}

void Print(Token *head, FILE *f){
  if(!f)
    f=fopen("dest", "w");
  while(head){
    fprintf(f, "%s = %d volte\n", head->stringa, head->n);
    head=head->next;
  }
  fclose(f);
}
