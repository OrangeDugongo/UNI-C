/*
        Date N stringhe in input, inserirle in una lista, far scegliere un
        carattere da tastiera e troncare tutte le stringhe a partire da quel
        carattere. Implementare poi la stampa della lista.

        Es: Inserite le stringhe: pippo, pluto, topolino; scelto il carattere
        'i' il programma dovrà stampare "pi, pluto, topoli"
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Nodo{
    char *str;
    struct Nodo *next;
} Nodo;

void Inserisci(int i);
void Tronca(char *str, char c);

Nodo *head=NULL;//Testa della lista

int main(){
    int n, i=0;
    char c;

    do{
        if(i++)
            printf("ERRORE\nSono consentiti solo interi positivi\n");

        printf("Quante stringhe vuoi inserire: ");
        scanf("%d", &n);
    }while(n<=0);

    for(i=0; i<n; i++)
        Inserisci(i+1);

    fflush(stdin);//Pulizia dello stream di input
    printf("Inserisci il carattere da cui troncare: ");
    scanf("%c", &c);

    while(head){
        Tronca(head->str, c);
        printf("%s\n", head->str);
        head=head->next;
    }
}

void Inserisci(int i){
    char buff[200];
    Nodo *New=(Nodo *)malloc(sizeof(Nodo));//Alloco il nuovo Nodo

    //Rischiesta di I/O
    printf("Inserisci la %d° stringa: ", i);
    scanf("%s", buff);

    New->str=(char *)calloc(strlen(buff)+1, sizeof(char));
    strcpy(New->str, buff);

    //Inserimento in coda
    New->next=head;
    head=New;
}

void Tronca(char *str, char c){
    int i;

    for(i=0; str[i]; i++)
        if(str[i]==c)
            str[i+1]='\0';//fine della stringa

    str=(char *)realloc(str, (strlen(str)+1)*sizeof(char));//Libero la memoria non più in uso
}
