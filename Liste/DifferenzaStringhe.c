/**
Inserite due stringhe stampa i caratteri presenti solo nella prima a mo di lista
**/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct carattere{
  char c;
  struct carattere *next;
}Carattere;

int main(){
  unsigned int i, j, ok;
  char str1[100], str2[100];
  Carattere *root=NULL, *lista;
  printf("inserisci la prima stringa: ");
  scanf("%s", str1);
  printf("inserisci la seconda stringa: ");
  scanf("%s", str2);
  if(strcmp(str1, str2)){
    for(i=0;i<strlen(str1);i++){
      ok=1;
      for(j=0;j<strlen(str2)&&ok;j++)
        if(str1[i]==str2[j])
          ok=0;
      if(ok){
        lista =(Carattere *)malloc(sizeof(Carattere));
        lista->c=str1[i];
        lista->next=root;
        root=lista;
      }
    }
    while(root){
      printf("%c --> ", root->c);
      root=root->next;
    }
    printf("FINE");
  }else
    printf("Le due stringhe sono uguali");

  __fpurge(stdin);
  getchar();
}
