#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char *nome;
    char *cognome;
    int eta;
} Persona;

char buffer[200];
void Swap(Persona p[], int i);
void Sort(Persona p[], int dim);
void Inserisci(Persona p[], int dim);
void Print(Persona p[], int dim);


int main(){
    int dim;
    Persona *p;
    printf("Qunte persone vuoi inserire: ");
    scanf("%d", &dim);

    p=(Persona *) calloc(dim, sizeof(Persona));
    Inserisci(p, dim);
    if(dim>1)
        Sort(p, dim);
    Print(p, dim);
    printf("\n\n----%d------", count);

    __fpurge(stdin);
    getchar();
}

void Inserisci(Persona p[], int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("Inserisci il cognome: ");
        scanf("%s",buffer);
        p[i].cognome=(char *)calloc(strlen(buffer)+1, sizeof(char));
        strcpy(p[i].cognome, buffer);

        printf("Inserisci il nome: ");
        scanf("%s", buffer);
        p[i].nome=(char *)calloc(strlen(buffer+1), sizeof(char));
        strcpy(p[i].nome, buffer);

        printf("Inserisci l'et�: ");
        scanf("%d", &p[i].eta);


    }
}

void Swap(Persona p[], int i){
    int j=i+1, temp;
    strcpy(buffer, p[i].cognome);
    strcpy(p[i].cognome, p[j].cognome);
    strcpy(p[j].cognome, buffer);

    strcpy(buffer, p[i].nome);
    strcpy(p[i].nome, p[j].nome);
    strcpy(p[j].nome, buffer);

    temp=p[i].eta;
    p[i].eta=p[j].eta;
    p[j].eta=temp;
}

void Sort(Persona p[], int dim){
    int i, ok;
    dim--;
    do{
        ok=1;
        for(i=0;i<dim;i++)
            if(strcmp(p[i].cognome, p[i+1].cognome)>0){
                Swap(p, i);
                ok=0;
            }
    }while(--dim>1 && !ok);
}

void Print(Persona p[], int dim){
    int i;
    for(i=0;i<dim;i++)
        printf("\n\n\n%s %s di %d anni", p[i].cognome, p[i].nome, p[i].eta);
}
