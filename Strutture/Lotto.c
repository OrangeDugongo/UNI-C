#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, d, e, e1, e2, e3 , e4, e5, count, n, i, bet;

    srand(time(NULL));
    i=1;

    do {
        printf("Quanti numeri vuoi giocare(min 3, Max 5): ");
        scanf("%d", &n);
    }
    while(n<3 || n>5);

    switch(n){
        case 5: do{
                    printf("Inserisci il %d° numero: ", i);
                    scanf("%d", &a);
                }
                while(a<1 || a>90);
                i++;
        case 4: do{
                    printf("Inserisci il %d° numero: ", i);
                    scanf("%d", &b);
                }
                while(b<1 || b>90 || a==b);
                i++;
        case 3: do{
                    printf("Inserisci il %d° numero: ", i);
                    scanf("%d", &c);
                }
                while(c<1 || c>90 || c==b || c==a);
                i++;
                do{
                    printf("Inserisci il %d° numero: ", i);
                    scanf("%d", &d);
                }
                while(d<1 || d>90 || d==c || d==b || d==a);
                i++;
                do{
                    printf("Inserisci il %d° numero: ", i);
                    scanf("%d", &e);
                }
                while(e<1 || e>90 || e==d || e==c || e==b || e==a);
    }

    printf("Hai giocato i seguenti numeri: ");
    if (n==5)
        printf("%d, %d, %d, %d, %d.\n", a, b, c, d, e);
    else if (n==4)
        printf("%d, %d, %d, %d.\n", b, c, d, e);
    else
        printf("%d, %d, %d.\n", c, d, e);

    do{
        printf("Quanto vuoi puntare? ");
        scanf("%d", &bet);
    }
    while(bet<=0);

    e1 = rand()%90+1;
    do
        e2 = rand()%90+1;
    while(e2==e1);
    do
        e3 = rand()%90+1;
    while(e3==e1 || e3==e2);
    do
        e4 = rand()%90+1;
    while(e4==e3 || e4==e2 || e4==e1);
    do
        e5 = rand()%90+1;
    while(e5==e4 || e5==e3 || e5==e2 || e5==e1);

    printf("Sono stati estratti i seguenti numeri: %d, %d, %d, %d, %d.\n", e1, e2, e3, e4, e5);

    if (a == e1 || a == e2 || a == e3 || a == e4 || a == e5)
        count++;
    if (b == e1 || b == e2 || b == e3 || b == e4 || b == e5)
        count++;
    if (c == e1 || c == e2 || c == e3 || c == e4 || c == e5)
        count++;
    if (d == e1 || d == e2 || d == e3 || d == e4 || d == e5)
        count++;
    if (e == e1 || e == e2 || e == e3 || e == e4 || e == e5)
        count++;

    switch(count){
        case 5: bet=bet*1000000;
                printf("Congratulazioni, hai fatto cinquina. Hai vinto %d€.", bet);
            break;
        case 4: bet=bet*10000;
                printf("Congratulazioni, hai fatto quaterna. Hai vinto %d€.", bet);
            break;
        case 3: bet=bet*100;
                printf("Congratulazioni, hai fatto terno. Hai vinto %d€.", bet);
            break;
        case 2: bet=bet*10;
                printf("Congratulazioni, hai fatto ambo. Hai vinto %d€.", bet);
            break;
        default: printf("Mi dispiace, hai perso. Ritenta e sarai più fortunato(In realtà avrai le stesse probabilità di prima, ma noi vogliamo i tuoi soldi).");
    }
}
