#include <stdio.h>
#include <stdlib.h>

void Date(int[], int);
int Tot(int[]);

int main()
{
    int data1[3], data2[3], i, delta, deltaAnni, deltaMesi, deltaDay;
    i=1;

    Date(data1, i);
    i++;
    Date(data2, i);

    delta= abs(Tot(data1)-Tot(data2));
    deltaAnni= delta/360;
    deltaMesi= (delta%360)/30;
    deltaDay= delta-(deltaMesi+deltaAnni*12)*30;

    printf("Tra il %d/%d/%d e il %d/%d/%d intercorrono: %d giorni, %d mesi, %d anni.", data1[2], data1[1], data1[0], data2[2], data2[1], data2[0], deltaDay, deltaMesi, deltaAnni);
}

void Date(int x[], int i){
    int j=0;
    do{
        if(j!=0)
            printf("Dati inseriti non validi, riprovare.\n------------\n");
        printf("Inserisci l'anno della %d° data: ", i);
        scanf("%d", &x[0]);
        j++;
    }while(x[0]>9999);
    j=0;
    do{
        if(j!=0)
            printf("Dati inseriti non validi, riprovare.\n------------\n");
        printf("Inserisci il mese della %d° data: ", i);
        scanf("%d", &x[1]);
        j++;
    }while(x[1]>12 || x[1]<1);
    j=0;
    do{
        if(j!=0)
            printf("Dati inseriti non validi, riprovare.\n------------\n");
        printf("Inserisci il giorno della %d° data: ", i);
        scanf("%d", &x[2]);
        j++;
    }while(x[2]<1 || x[2]>30);
}

int Tot(int x[]){
    int tot;
    tot= (x[1]+x[0]*12)*30+x[2];
    return(tot);
}
