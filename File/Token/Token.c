#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdio_ext.h>

typedef struct Token{
  char *stringa;
  int nOcc;
  struct Token *next;
} Token;

void Print(Token *);

int main(){
  FILE *fp;
  Token *head=NULL;
  char buffer[256];
  printf("Quale file di testo vuoi caricare: ");
  scanf("%s", buffer);
  fp=fopen(buffer, "r");

  while(fscanf(fp, "%s", buffer) != EOF){
    Token *cur=head;
    Token *pre=NULL;
    if(!cur || strcmp(buffer, cur->stringa)<0){
      Token *n = (Token *)malloc(sizeof(Token));
      n->stringa= (char *)malloc((strlen(buffer)+1)*sizeof(char));
      strcpy(n->stringa, buffer);
      n->nOcc=1;
      n->next=head;
      head=n;
    }else{
      while(cur && strcmp(buffer, cur->stringa)>=0){
        pre=cur;
        cur=cur->next;
      }
        if(!strcmp(buffer, cur->stringa))
          (cur->nOcc)++;
        else{
          Token *n = (Token *)malloc(sizeof(Token));
          n->stringa= (char *)malloc((strlen(buffer)+1)*sizeof(char));
          strcpy(n->stringa, buffer);
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
    printf("%s = %d   --->   ", head->stringa, head->nOcc);
    head=head->next;
  }
  printf("FINE");
}
