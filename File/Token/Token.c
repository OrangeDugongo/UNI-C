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
    Token *pre=NULL, *cur=head;
    while(cur && strcmp(buffer, cur->stringa)>0){
      pre=cur;
      cur=cur->next;
    }
    if(cur && !strcmp(buffer, cur->stringa))
      (cur->nOcc)++;
    else{
      Token *New=(Token *)malloc(sizeof(Token));
      New->stringa=(char *)calloc(strlen(buffer)+1, sizeof(char));
      strcpy(New->stringa, buffer);
      New->nOcc=1;
      if(!pre){
        New->next=head;
        head=New;
      }else{
        New->next=cur;
        pre->next=New;
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
