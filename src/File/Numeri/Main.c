#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdio_ext.h>

typedef struct token{
  int i;
  int nOcc;
  struct token *next;
} Token;

void Print(Token *);
int Trovato(Token *, int);

int main(){
  FILE *fp;
  Token *head=NULL, *l, *pre, *cur;
  int j;
  fp=fopen("Numeri", "r");

  while(fscanf(fp, "%d", &j) != EOF){
    if(!Trovato(head, j)){
      pre=NULL;
      cur=head;
      l=(Token *)malloc(sizeof(Token));
      l->i=j;
      l->nOcc=1;
      if(!cur || j<cur->i){
        l->next=head;
        head=l;
      }else{
        while(cur && j>cur->i){
          pre=cur;
          cur=cur->next;
        }
        pre->next=l;
        l->next=cur;
      }
    }
  }
  Print(head);
  fclose(fp);
  __fpurge(stdin);
  getchar();
}

int Trovato(Token *head, int j){
  int trovato=0;
  while(head && head->i<=j){
    if(head->i==j){
      (head->nOcc)++;
      trovato=1;
    }
    head=head->next;
  }
  return(trovato);
}

void Print(Token *h){
  Token *head=h;
  while(head){
    printf("%d = %d volte\n", head->i, head->nOcc);
    head=head->next;
  }
  printf("FINE");
}
