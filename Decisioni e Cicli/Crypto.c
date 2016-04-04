#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, prima, seconda, terza, quarta, option;

    printf("Scegli l'opzione che desiderei\n1) Cripta\n2) Decripta\n");
    scanf("%d", &option);

    switch(option){

    case 1: printf("Inserisci il numero da criptare (quattro cifre): ");
            scanf("%d", &n);
            prima= (n/1000 +7)%10;
            seconda= ((n/100)%10 +7)%10;
            terza= ((n/10)%10 +7)%10;
            quarta= (n%10 +7)%10;
            m = terza*1000 + quarta*100 + prima*10 + seconda;
            printf("Il tuo numero è: %d", m);
        break;

    case 2: printf("Inserisci il numero da decriptare(quattro cifre): ");
            scanf("%d", &n);
            prima= (n/1000 +3)%10;
            seconda= ((n/100)%10 +3)%10;
            terza= ((n/10)%10 +3)%10;
            quarta= (n%10 +3)%10;
            m = terza*1000 + quarta*100 + prima*10 + seconda;
            printf("Il tuo numero è: %d", m);
        break;

    default: printf("il numero inserito non è valido.");

    }


}
