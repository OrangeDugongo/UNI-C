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

void InserisciAula(Studente a[]);
void InserisciEsami(Esame e[], Studente a[]);
int Controllo( Studente a[], int i);
void Print(Studente a[], Esame e[]);
int Count(int mat, Esame e[]);
float Media(int mat, Esame e[]);
int Check(Studente a[], int mat);

int main(){
  Studente aula[AULA];
  Esame esame[ESAMI];

  InserisciAula(aula);
  InserisciEsami(esame, aula);
  Print(aula, esame);

  __fpurge(stdin);
  getchar();

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
    }while(Controllo(a, i));
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
    }while(Check(a, e[i].matricola));
    printf("\n-----------------\n\n");
  }
}

int Controllo( Studente a[], int i){
  int j;
  for(j=0;j<i;j++)
    if(a[j].matricola==a[i].matricola)
      return(1);
  return(0);
}

void Print(Studente a[], Esame e[]){
  int i;
  for(i=0;i<AULA;i++)
    printf("Lo studente %s %s ha sostenuto %d esami con la media di %.2f.\n", a[i].nome, a[i].cognome, Count(a[i].matricola, e), Media(a[i].matricola, e));
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

int Check(Studente a[], int mat){
  int i;
  for(i=0;i<AULA;i++)
    if(a[i].matricola==mat)
      return(0);
  return(1);
}
