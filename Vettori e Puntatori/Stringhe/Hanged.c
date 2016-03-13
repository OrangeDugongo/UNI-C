#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
void Read(char *);
void Copy(char *, char *);
int Check(char *s, char *d, char c);
int Win(char *s, char *d);
void Life(int sum);
const int MAX = 80;

int main(){
  char f[MAX], fIndovina[MAX], c;
  int life=3, j;

  printf("si consiglia di ridurre l'altezza della shell.\n");
  printf("Giocatore 1: Inserisci la frase: ");
  Read(f);
  Copy(f, fIndovina);
  printf("\n\n\n\n\n\n");
  do{
    printf("Indovina la frase: %s", fIndovina);

    do{
      printf("\nGiocatore 2 ");
      Life(life);
      printf(": tentativo: ");
      __fpurge(stdin);
      scanf("%c", &c);
    }while(!isalpha(c));

    life-=Check(f, fIndovina, c);
  }while(!(j=Win(f, fIndovina)) && life>=0);

  if(j)
    printf("\n%s\nYou Win!", fIndovina);
  else
    printf("\nYou lose!");
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

int Check(char *s, char *d, char c){
  int i, check=1;
  for(i=0;*(s+i)!='\0';i++){
    if(c==*(s+i)){
      *(d+i)=*(s+i);
      check=0;
    }
  }
  return(check);
}

int Win(char *s, char *d){
  int win=1, i;
  for(i=0;*(s+i)!='\0' && win==1;i++){
    if(*(s+i)!=*(d+i))
      win=0;
  }
  return(win);
}

void Life(int sum){
  switch(sum){
    case 1: printf("<3");
      break;
    case 2: printf("<3 <3");
      break;
    case 3: printf("<3 <3 <3");
      break;
    default: printf("last chance");
  }
}
