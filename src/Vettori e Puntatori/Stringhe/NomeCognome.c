#include <stdio.h>
#include <ctype.h>
const int DIM=80;
void Inserisci(char *p);
void Up(char *p);

int main(){
  char nome[DIM];

  Inserisci(nome);
  Up(nome);
}

void Inserisci(char *p){
  int i;
  printf("inserisci il nome e il cognome: ");
  for(i=0;i<DIM-1 && (*(p+i)=tolower(getchar()))!='\n';i++);
  *(p+i)='\0';
}

void Up(char *p){
  int i;

  *p=toupper(*p);
  for(i=0;*(p+i);i++)
    if(isspace(*(p+i)))
      *(p+i+1)=toupper(*(p+i+1));
}
