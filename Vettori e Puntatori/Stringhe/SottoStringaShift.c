/* Scrivere un programma che elimina da una stringa una sottostringa*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

int Sub(char *, char *, int);

int main(){
  char *str=(char *)malloc(200*sizeof(char));
  char *sub=(char *)malloc(200*sizeof(char));
  unsigned int i, j;

  printf("inserisci la stringa: ");
  scanf("%s", str);
  str=(char *)realloc(str, (strlen(str)+1)*sizeof(char));
  printf("inserisci la sotto stringa: ");
  scanf("%s", sub);
  sub=(char *)realloc(sub, (strlen(sub)+1)*sizeof(char));

  for(i=0;i<strlen(str);i++)
    if(Sub(str, sub, i)){
      for(j=0;i+j<=strlen(str);j++)
        str[i+j]=str[i+j+strlen(sub)];
      i--;
    }

  str=(char *)realloc(str, (strlen(str)+1)*sizeof(char));

  printf("\n%s", str);
  __fpurge(stdin);
  getchar();
}

int Sub(char *str, char *sub, int i){
  int unsigned ok=1, j;

  for(j=0;j<strlen(sub) && ok;j++)
    if(str[i+j]!=sub[j])
      ok=0;

  return ok;
}
