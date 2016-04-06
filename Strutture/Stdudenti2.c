#include <stdio.h>
#define NOME 20
#define GNOME 30
#define DIM 4

typedef struct{
  char nome[NOME];
  char cognome[GNOME];
  int voto;
} Studente;

void Inserisci(Studente a[]);
void Print(Studente a[]);
float Media(Studente a[]);

int main(){
  Studente aula[DIM];

  Inserisci(aula);
  Print(aula);
  printf("la media dei voti è %.2f", Media(aula));
  getchar();
}

void Inserisci(Studente a[]){
  int i;
  for(i=0;i<DIM;i++){
    printf("Inserisci il nome del %d° studente: ", i+1);
    scanf("%s", a[i].nome);
    printf("Inserisci il cognome del %d° studente: ", i+1);
    scanf("%s", a[i].cognome);
    do{
      printf("Inserisci il voto d'esame del %d° studente: ", i+1);
      scanf("%d", &a[i].voto);
    }while(a[i].voto<18 || a[i].voto>30);
    printf("\n-----------------\n\n");
  }
}

void Print(Studente a[]){
  int i;
  for(i=0;i<DIM;i++)
    printf("%s %s\n", a[i].nome, a[i].cognome);
}

float Media(Studente a[]){
  int i;
  float media=0;
  for(i=0;i<DIM;i++)
    media+=a[i].voto;
  return(media/DIM);
}
