#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
void Read(char *);
void Copy(char *, char *);
void Check(char *s, char *d, char c);
int Win(char *s, char *d);
const int MAX = 80;

int main(){
  char f[MAX], fIndovina[MAX], c;

  printf("Giocatore 1: Inserisci la frase: ");
  Read(f);
  Copy(f, fIndovina);
  do{
    printf("Indovina la frase: %s", fIndovina);
    printf("\nGiocatore 2: tentativo: ");
    __fpurge(stdin);
    scanf("%c", &c);
    Check(f, fIndovina, c);
  }while(!Win(f, fIndovina));
  printf("\n%s\nYou Win!", fIndovina);
}

void Read(char *p){
  int i;
  for(i=0;i<MAX && (*(p+i)=getchar())!='\n';i++);
  *(p+i)='\0';
}

void Copy(char *s, char *d){
  int i;
  for(i=0;(*(d+i)=*(s+i))!='\0';i++){
    if(isalpha(*(d+i)))
      *(d+i)='_';
  }
}

void Check(char *s, char *d, char c){
  int i;
  for(i=0;*(s+i)!='\0';i++){
    if(c==*(s+i))
      *(d+i)=*(s+i);
  }
}

int Win(char *s, char *d){
  int win=1, i;
  for(i=0;*(s+i)!='\0' && win==1;i++){
    if(*(s+i)!=*(d+i))
      win=0;
  }
  return(win);
}
