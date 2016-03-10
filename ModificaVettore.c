#include <stdio.h>

int main(){
  int v[3]={1,2,3};;
  *(v+1)*=10;
  printf("%d", v[1]);
}
