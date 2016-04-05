#include <stdio.h>
#include <string.h>
#define NOME 20
#define GNOME 30
#define DIM 100

struct Studente{
  char nome[NOME];
  char cognome[GNOME];
  char nascita[15];
  int esami;
  int matricola;
};

void Inserimento(int, struct Studente aula[]);
int Search(struct Studente a[], int dim, int mat);

int main(int argc, char *argv[]){
  struct Studente aula[DIM];
  int riemp, mat, i;

  do{
    printf("Quanti studenti vuoi inserire: ");
    scanf("%d", &riemp);
  }while(riemp<1 || riemp>DIM);

  Inserimento(riemp, aula);

  do{
    printf("Inserisci la matricola dello studente da cercare: ");
    scanf("%d", &mat);

    if((i=Search(aula, riemp, mat))>=0)
      printf("lo studente %s %s nato il %s ha sostenuto %d esami.\n", aula[i].nome, aula[i].cognome, aula[i].nascita, aula[i].esami);
    else
      printf("Studente non trovato.\n");
    }while(1);
  __fpurge(stdin);
  getchar();
}

void Inserimento(int dim, struct Studente aula[]){
  int i;
  for(i=0;i<dim;i++){
    printf("Inserisci il nome dello studente: ");
    scanf("%s", aula[i].nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s", aula[i].cognome);
    printf("Inserisci il numero di matricola dello studente: ");
    scanf("%d", &(aula[i].matricola));
    printf("Inserisci la data di nascita dello studente(gg-mm-aa): ");
    scanf("%s", aula[i].nascita);
    printf("Inserisci il numero di esami sostenuti dello studente: ");
    scanf("%d", &(aula[i].esami));
    printf("\n---------------------\n\n");
    __fpurge(stdin);
  }
}

int Search(struct Studente a[], int dim, int mat){
  int i;
  for(i=0;i<dim;i++)
    if(a[i].matricola==mat)
      return(i);
  return(-1);
}
