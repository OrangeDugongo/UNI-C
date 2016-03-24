#include <stdio.h>
#include <string.h>
const int DIM=80;
void Inserisci(int, char *);
int Search(char p1[], char p2[]);

int main(){
  char str1[DIM], str2[DIM];

  Inserisci(1, str1);
  Inserisci(2, str2);

  if(strlen(str1)>strlen(str2))
    printf("%d", Search(str1, str2));
  else
    printf("%d", Search(str2, str1));
}

void Inserisci(int i, char *p){
  int j;
  printf("inserisci la %d° stringa: ", i);
  for(j=0;j<DIM-1 && (*(p+j)=getchar())!='\n';j++);
  *(p+j)='\0';
}

int Search(char p1[], char p2[]){
  int ok, i, j;
  for(i=0;p1[i];i++){
    ok=1;
    for(j=0;j<strlen(p2) && ok;j++){
      if(p1[i+j]!=p2[j])
        ok=0;
    }
    if(ok)
      break;
  }
  return ok;
}
