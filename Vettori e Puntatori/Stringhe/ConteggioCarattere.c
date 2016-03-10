#include <stdio.h>
#include <stdio_ext.h>
int Conta(char *, char);
const int MAX = 80;

int main(){
  char linea[MAX], c;
  int i;

  printf("Inserisci una linea.\n");
  for(i=0; i<MAX-1 && (linea[i]=getchar())!='\n' ;i++);
  linea[i]='\0';

  //while ((c=getchar())!=EOF && c!='\n');
  __fpurge(stdin); //alternativa fflush
  printf("\nInserisci il carattere che vuoi ricercare: ");
  //scanf("%*[^\n]\n%c", &c); non funziona con strinche più corte di 9
  scanf("%c", &c);

  printf("Nella stringa \"%s\" il carattere \"%c\" è presente %d volta\\e", linea, c, Conta(linea, c));
}


int Conta(char *l, char c){
  int i, count=0;
  for(i=0;*(l+i)!='\0';i++){
    if(*(l+i)==c)
      count++;
  }
  return(count);
}
