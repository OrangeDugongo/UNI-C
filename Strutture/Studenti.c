#include <stdio.h>
#include <malloc.h>
#include <string.h>
char buffer[200];

struct Studente{
  char *nome;
  char *cognome;
  char *nascita;
  int esami;
  int matricola;
};

void Inserimento(int, struct Studente aula[]);
int Search(struct Studente a[], int dim, int mat);

int main(int argc, char *argv[]){
  struct Studente *aula;
  int riemp, mat, i;

  do{
    printf("Quanti studenti vuoi inserire: ");
    scanf("%d", &riemp);
  }while(riemp<1);
  aula=(struct Studente*) calloc(riemp, sizeof(aula));
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
    scanf("%s", buffer);
    aula[i].nome=(char*) calloc(strlen(buffer)+1, sizeof(char));
    strcpy(aula[i].nome, buffer);

    printf("Inserisci il cognome dello studente: ");
    scanf("%s", buffer);
    aula[i].cognome=(char*) calloc(strlen(buffer)+1, sizeof(char));
    strcpy(aula[i].cognome, buffer);

    printf("Inserisci il numero di matricola dello studente: ");
    scanf("%d", &(aula[i].matricola));

    printf("Inserisci la data di nascita dello studente(gg-mm-aa): ");
    scanf("%s", buffer);
    aula[i].nascita=(char*) calloc(strlen(buffer)+1, sizeof(char));
    strcpy(aula[i].nascita, buffer);

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
