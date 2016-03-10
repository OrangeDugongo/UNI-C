#include <stdio.h>
#include <stdlib.h>

int abs(int);
void ValAss(int vettore[], int vettoreAssoluto[]);
void Riempimento(int a[]);
void Stampa(int a[]);
const int dim=10;
int i;

int main()
{
    int vet[dim], vetAss[dim];

    Riempimento(vet);
    ValAss(vet, vetAss);
    printf("-----------------------------------------------\n");
    Stampa(vetAss);

}

int Abs(int a){
    if(a<0)
        a=-a;
    return(a);
}

void ValAss(int vettore[], int vettoreAssoluto[]){
     for(i=0;i<dim;i++){
        vettoreAssoluto[i]= Abs(vettore[i]);
    }
}

void Riempimento(int a[]){
    for(i=0;i<dim;i++){
        printf("Inserisci il valore del %d° elemento del vettore: ", i+1);
        scanf("%d", &a[i]);
    }
}

void Stampa(int a[]){
    for(i=0;i<dim;i++)
        printf("Il valore del %d° elemento del vettore vale: %d\n" , i+1, a[i]);
}
