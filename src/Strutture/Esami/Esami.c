#include <stdio.h>
#define NOME 20
#define GNOME 30
#define ESAMI 3
#define AULA 2

typedef struct{
  char nome[NOME];
  char cognome[GNOME];
  int matricola;
} Studente;

typedef struct{
  int matricola;
  int voto;
  char nomeEsame[NOME];
} Esame;

int Search(Studente a[], int mat){
  int i;
  for(i=0;i<AULA;i++)
    if(a[i].matricola==mat)
      return(i);
  return(-1);
}

int Esiste( Studente a[], int mat, int i){
  int j;
  for(j=0;j<i;j++)
    if(a[j].matricola==mat)
      return(1);
  return(0);
}

int Count(int mat, Esame e[]){
  int i, count=0;
  for(i=0;i<ESAMI;i++)
    if(e[i].matricola==mat)
      count++;
  return(count);
}

float Media(int mat, Esame e[]){
  int i, media=0, count=0;
  for(i=0;i<ESAMI;i++)
    if(e[i].matricola==mat){
      media+=e[i].voto;
      count++;
    }
  return(media/count);
}

void InserisciAula(Studente a[]){
  int i;
  for(i=0;i<AULA;i++){
    printf("Inserisci il nome del %d° studente: ", i+1);
    scanf("%s", a[i].nome);
    printf("Inserisci il cognome del %d° studente: ", i+1);
    scanf("%s", a[i].cognome);
    do{
      printf("Inserisci il numero di matricola del %d° studente: ", i+1);
      scanf("%d", &a[i].matricola);
    }while(Esiste(a, a[i].matricola, i));
    printf("\n-----------------\n\n");
  }
}

void InserisciEsami(Esame e[], Studente a[]){
  int i;
  for(i=0;i<ESAMI;i++){
    printf("Inserisci il nome del %d° esame: ", i+1);
    scanf("%s", e[i].nomeEsame);
    do{
      printf("Inserisci il voto del %d° esame: ", i+1);
      scanf("%d", &e[i].voto);
    }while(e[i].voto<18 || e[i].voto>30);
    do{
      printf("Inserisci il numero di matricola dello studente: ");
      scanf("%d", &e[i].matricola);
    }while(!Esiste(a, e[i].matricola, AULA));
    printf("\n-----------------\n\n");
  }
}

void PrintAula(Studente a[], Esame e[]){
  int i;
  for(i=0;i<AULA;i++)
    printf("Lo studente %s %s ha sostenuto %d esami con la media di %.2f.\n", a[i].nome, a[i].cognome, Count(a[i].matricola, e), Media(a[i].matricola, e));
}

void PrintStudente(Studente a[], Esame e[]){
  int mat, j=0;
  do{
    if(j<0)
      printf("Lo studente non esiste.\n");
    printf("inserisci il numero di matricola dello studente: ");
    scanf("%d", &mat);
  }while((j=Search(a, mat))<0);
  printf("Lo studente %s %s ha sostenuto %d esami con la media di %.2f.\n", a[j].nome, a[j].cognome, Count(mat, e), Media(mat, e));
}

void Menu(Studente a[], Esame e[], int menu){
  switch (menu){
    case 1: PrintAula(a, e);
      break;
    case 2: PrintStudente(a,e);
      break;
  }
}
