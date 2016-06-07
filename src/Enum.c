#include <stdio.h>

int main(){
  typedef enum {lu=1, ma, me, gi, ve, sa, dom} giorni;
  giorni oggi;

  do{
    printf("\nInserisci il giorno ");
    scanf("%d", &oggi);
    switch(oggi){
      case lu: printf("Lunedì");
        break;
      case ma: printf("Martedì");
        break;
      case me: printf("Mercoledì");
        break;
      case gi: printf("Giovedì");
        break;
      case ve: printf("Venerdì");
        break;
      case sa: printf("Sabato");
        break;
      case dom: printf("Domenica");
        break;
    }
  }while(1);
  __fpurge(stdin);
  getchar();
}
