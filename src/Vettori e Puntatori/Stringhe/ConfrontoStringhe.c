#include <stdio.h>

int main(int argc, char *argv[]){
  int k;

  for(k=0;*(argv[1]+k)==*(argv[2]+k) && *(argv[1]+k) && *(argv[2]+k);k++);

  if(*(argv[1]+k)==*(argv[2]+k))
    printf("Le due stringhe sono uguali.");
  else if(!*(argv[1]+k))
    printf("La prima stringa è più corta.");
  else if(!*(argv[2]+k))
    printf("La seconda stringa è più corta.");
  else
    printf("Le due stringhe sono diverse.");
}
