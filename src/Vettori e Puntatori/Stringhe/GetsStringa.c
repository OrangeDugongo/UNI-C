#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
int isspace(int);
int toupper(int);
void Prova(char *s);

int main(){
  char s[180];
  gets(s);
  Prova(s);
  printf("%s", s);
  __fpurge(stdin);
  getchar();
}

void Prova(char *s){
  int i=0;
  while(!isspace(s[i])){
    s[i]=toupper(s[i]);
    i++;
  }
}
