#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, rosso, blu, countRosso, countBlu, pari;

    srand(time(NULL));
    countBlu=0;
    countRosso=0;
    pari=0;

    for(i=1; i<10; i++){
        rosso = rand()%6+1;
        blu = rand()%6+1;
        printf("Rosso: %d \nBlu %d\n---------\n", rosso, blu);
        if (rosso == blu)
            pari++;
        else if (rosso>blu)
            countRosso++;
        else
            countBlu++;
    }

    if (countRosso == countBlu)
        printf("La partita è finita in parità.\n");
    else if (countRosso>countBlu)
        printf("La partita è stata vinta dal rosso.\nIl giocatore rosso ha vinto %d partite.\nIl giocatore blu ha vinto %d partite.", countRosso, countBlu);
    else
        printf("La partita è stata vinta dal blu.\nIl giocatore blu ha vinto %d partite.\nIl giocatore rosso ha vinto %d partite.", countBlu, countRosso);
}
