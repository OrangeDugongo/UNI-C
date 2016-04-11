#include <stdio.h>
#include <malloc.h>
#include <string.h>


int main(){
  int i, j, h=1, ok;
  char str1[100], str2[100], *str;
  printf("inserisci la prima stringa: ");
  scanf("%s", str1);
  printf("inserisci la seconda stringa: ");
  scanf("%s", str2);

  str=(char*)malloc(h*sizeof(char));
  if(strcmp(str1, str2)){
    for(i=0;i<strlen(str1);i++){
      ok=1;
      for(j=0;j<strlen(str2)&&ok;j++)
        if(str1[i]==str2[j])
          ok=0;
      if(ok){
        str[h-1]=str1[i];
        str=(char*)realloc(str, ++h);
      }
    }
    str[h-1]='\0';
    printf("\n\nStringa: %s", str);
  }else
    printf("Le due stringhe sono uguali");

  __fpurge(stdin);
  getchar();
}
