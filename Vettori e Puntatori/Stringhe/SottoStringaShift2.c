/*
    Data "mamma" e "ma" il programma restituisce "#m#"
    data "abcdeabcfgabc" e "abc" il programma restituisce ""#de#fg#""
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdio_ext.h>

int Sub(char *str, char *sub, int i);

int main(){
  char *str=(char *)malloc(200*sizeof(char));
  char *sub=(char *)malloc(200*sizeof(char));
  unsigned int i, j;

  printf("Inserisci la prima stringa: ");
  scanf("%s", str);
  str=(char *)realloc(str, (strlen(str)+1)*sizeof(char));

  printf("Inserisci la seconda stringa: ");
  scanf("%s", sub);
  sub=(char *)realloc(sub, (strlen(sub)+1)*sizeof(char));

  if(strlen(sub)>strlen(str))
    printf("ERRORE\n");
  else{
    for(i=0;i<strlen(str);i++)
      if(Sub(str, sub, i)){
        str[i]='#';
        for(j=i+1;j<strlen(str);j++)
          str[j]=str[j+strlen(sub)-1];
      }
    str=(char *)realloc(str, sizeof(char)*(strlen(str)+1));
  }
  printf("%s", str);
  __fpurge(stdin);
  getchar();
}

int Sub(char *str, char *sub, int i){
  unsigned int j, ok=1;

  for(j=0;j<strlen(sub) && ok;j++)
    if(str[i+j]!=sub[j])
      ok=0;

  return ok;
}
