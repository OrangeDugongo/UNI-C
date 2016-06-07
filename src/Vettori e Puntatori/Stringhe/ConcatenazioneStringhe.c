#include <stdio.h>

int main(int argc, char *argv[]){
  const int MAX=10;
  char dest[MAX];
  int i, k=0, p;

  for(i=1;argv[i] && k<MAX-1;i++)
    for(p=0;*(argv[i]+p) && k<MAX-1;dest[k++]=*(argv[i]+p++));

  dest[k]='\0';
  printf("\n\n%s", dest);
}
