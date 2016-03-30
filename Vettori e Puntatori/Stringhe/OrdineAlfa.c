#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  int i, j;
  j=argc-1;
  do
    for(i=1;i<j;i++)
      if(strcmp(argv[i], argv[i+1])>0){
        argv[0]=argv[i];
        argv[i]=argv[i+1];
        argv[i+1]=argv[0];
      }
  while(--j>1);
  for(i=1;i<argc;i++){
    printf("%s\n", argv[i]);
  }
}
