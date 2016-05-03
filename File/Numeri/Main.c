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

int main(){
  FILE *fp;
  Token *head=NULL;
  int j;
  fp=fopen("Numeri", "r");

  while(fscanf(fp, "%d", &j) != EOF){
    Token *cur=head;
    Token *pre=NULL;
    if(!cur || j<cur->i){
      Token *n= (Token *)malloc(sizeof(Token));
      n->i=j;
      n->nOcc=1;
      n->next=head;
      head=n;
    }else{
      while(cur && cur->i<=j){
        pre=cur;
        cur=cur->next;
      }
        if(cur->i==j)
          (cur->nOcc)++;
        else{
          Token *n = (Token *)malloc(sizeof(Token));
          n->i=j;
          n->nOcc=1;
          pre->next=n;
          n->next=cur;
        }
    }
  }
  Print(head);
  fclose(fp);
  __fpurge(stdin);
  getchar();
}

void Print(Token *h){
  Token *head=h;
  while(head){
    printf("%d = %d volte   --->   ", head->i, head->nOcc);
    head=head->next;
  }
  printf("FINE");
}
