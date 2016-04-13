
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define Nn 20
#define Nc 30
#define Dt 15
#define Aa 100
const int SLOT=3;

struct Studenti {
  char *nome ;
  char *cognome;
  char *data;
  int esami_sostenuti;
};

int Ricerca (char [], struct Studenti [], int);
void Stampa (struct Studenti [], int);
struct Studenti* Inserisci (struct Studenti [], int*, int*);

 int main (int argc, char *argv[]){
   struct Studenti *Aula;
   int menu, riemp=0, dim=SLOT;

   Aula= (struct Studenti*) malloc(SLOT*sizeof(struct Studenti));

   do{
     printf ("    ----------Menu'----------");
     printf ("\n 1. Inserisci nuovo studente");
     printf("\n 2. Ricerca studente");
     printf("\n 3. Modifica studente");
     printf ("\n 4. Stampa");
     printf("\n 0. Uscita dal rogramma");
     printf ("\n Quale funzione vuoi attivare: ");
     scanf ("%d", &menu);

     switch (menu) {
       case 1:Aula=Inserisci(Aula, &riemp, &dim); // Aula riemp e dim sono parametri di input/output per cui si passa per indirizzo
          break;
       case 2:
          break;
       case 3:
          break;
       case 4: printf("\n stampa della struttura: \n\n");
               Stampa (Aula, riemp);
          break;
       case 5:
          break;
      default: printf("il valore inserito non e' valido\n");
    }

 } while (menu);


 // printf ("Quanti studenti vuoi caricare? \n");
// scanf ("%d", &numero);

/* for (i=0; i<numero; i++){

    printf("\nInserisci il nome ");
    scanf ("%s",buffer); // non si mette & perch� gi� punta alla testa dell'array

    Aula[i].nome=(char*) malloc((strlen(buffer)+1)* sizeof(char)); //(char*) � un'oprazione di casting
    strcpy(Aula[i].nome, buffer);

    printf("\nInserisci il cognome ");
    scanf ("%s", buffer);

    Aula[i].cognome=(char *) malloc ((strlen (buffer)+1)* sizeof(char));
    strcpy (Aula[i].cognome, buffer);

    printf("\nInserisci la data (gg/mm/aaaa) ");
    scanf ("%s", buffer);

    Aula[i].data=(char *) malloc ((strlen (buffer)+1)* sizeof(char));
    strcpy (Aula[i].data, buffer);

    printf("\nInserisci il numero di esami sostenuti ");
    scanf ("%d", &(Aula[i].esame_sostenuti));

 }
 */
 /*printf("\n Dammi il cognome che vuoi ricercare: ");
 scanf ("%s", rice);

 trovato= Ricerca (rice, Aula, numero);

 if (trovato!=-1) {
    printf ("trovato e l'indice e': %d\n\n", trovato);
 }
 else printf("Non trovato\n\n");
*/

 }

int Ricerca (char cgn[], struct Studenti a[], int num){
  int i;
  for (i=0; i<num; i++)
    if (!strcmp(a[i].cognome, cgn))
      return (i+1); // i+1 perch� parte da zero l'array
  return -1;
}


void Stampa (struct Studenti a[], int riemp){
  int i;
    for (i=0; i<riemp; i++){
      printf ("\n\n Nome; %s", a[i]. nome);
      printf ("\n\n Cognome: %s", a[i]. cognome);
      printf ("\n\n Data: %s", a[i]. data);
      printf ("\n\n Esami sostenuti: %d", a[i].esami_sostenuti);
      printf ("\n\n");
    }
}

struct Studenti* Inserisci (struct Studenti sA [], int *pr, int *pd){
  char buffer [200];

  if ((*pr)==(*pd))
    sA=(struct Studenti*) realloc(sA, (*pd+=SLOT));

  printf("\nInserisci il nome ");
  scanf ("%s",buffer); // non si mette & perch� gi� punta alla testa dell'array
  sA[*pr].nome=(char *) malloc((strlen(buffer)+1)* sizeof(char));
  strcpy(sA[*pr].nome, buffer);

  printf("\nInserisci il cognome ");
  scanf ("%s", buffer);
  sA[*pr].cognome=(char *) malloc ((strlen (buffer)+1)* sizeof(char));
  strcpy (sA[*pr].cognome, buffer);

  printf("\nInserisci la data (gg/mm/aaaa) ");
  scanf ("%s", buffer);
  sA[*pr].data=(char *) malloc ((strlen (buffer)+1)* sizeof(char));
  strcpy (sA[*pr].data, buffer);

  printf("\nInserisci il numero di esami sostenuti ");
  scanf ("%d", &(sA[*pr].esami_sostenuti));

  (*pr)++;

  return sA;
}
