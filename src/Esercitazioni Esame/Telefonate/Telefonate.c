/*
    Preso un file di testo in cui è riportata la cità da cui è stata
    effettuata la chiamata, la durata della chiamata e gli scatti. I vari
    parametri sono separati da uno o più spazi.

    Esempio:
    ROMA 230 5
    MILANO 30 3
    ROMA 20 3

    Scrivere un programma C che preso in input il nome della città restituisca:
    * Il numero totale degli scatti.
    * La durata della telefonata più lunga e quella più corta.
    * Lunghezza media della telefonata.
    * Lista completa delle telefonate, in ordine decrescente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Call{
  char *city;
  int durata;
  int n;
  struct Call *next;
}Call;

void Read(FILE *src);
void Print(Call *stampa);
void Scatti(char *city);
void MaxMin(char *city);
void Media(char *city);
void PrintAll(char *city);

Call *head=NULL;

int main(){
  FILE *src;
  char buffer[200];
  int n;

  printf("Quale file vuoi aprire: ");
  scanf("%s", buffer);

  if(!(src=fopen(buffer, "r"))){
    printf("ERRORE\n Il file non esiste.");
    return 1;
  }

  Read(src);
  fclose(src);

  if(!head){
    printf("ERRORE\n Il file non ha elementi");
    return 1;
  }

  do{
    printf("\n\n1. Numero degli scatti.");
    printf("\n2. Max e Min telefonata.");
    printf("\n3. Lunghezza media.");
    printf("\n4. Stampap tutto.");
    printf("\n0. exit.");
    printf("\nCosa vuoi fare: ");
    scanf("%d", &n);
    if(n){
      printf("\nInserisci la città: ");
      scanf("%s", buffer);
    }
    switch(n){
      case 1: Scatti(buffer);
        break;
      case 2: MaxMin(buffer);
        break;
      case 3: Media(buffer);
        break;
      case 4: PrintAll(buffer);
        break;
      default: printf("Scelta non valida.");
        break;
      case 0: printf("Arrivederci.");
    }

  }while(n);
}


void Read(FILE *src){
  char buffer[200];
  Call *cur, *pre;

  while(fscanf(src, "%s", buffer) != EOF){
    Call *nuovo=(Call *)malloc(sizeof(Call));
    nuovo->city=(char *)calloc(strlen(buffer)+1, sizeof(char));
    strcpy(nuovo->city, buffer);
    fscanf(src, "%d", &nuovo->durata);
    fscanf(src, "%d", &nuovo->n);

    cur=head;
    pre=NULL;

    while(cur && nuovo->durata<cur->durata){
      pre=cur;
      cur=cur->next;
    }
    if(!pre){
      nuovo->next=head;
      head=nuovo;
    }else{
      nuovo->next=cur;
      pre->next=nuovo;
    }
  }
}

void Print(Call *stampa){
  printf("citta: %s ", stampa->city);
  printf("durata(in secondi): %d ", stampa->durata);
  printf("scatti: %d.\n", stampa->n);
}

void Scatti(char *city){
  Call *cur=head;
  int scatti=0;

  while(cur){
    if(!strcmp(cur->city, city))
      scatti+=cur->n;
    cur=cur->next;
  }

  printf("\n Totale scatti: %d", scatti);
}

void MaxMin(char *city){
  Call *cur=head, *max=NULL, *min=NULL;

  while(cur){
    if(!strcmp(cur->city, city)){
      if(!max || cur->durata>max->durata)
      max=cur;

      if(!min || cur->durata<min->durata)
      min=cur;
    }
    cur=cur->next;
  }
  printf("Chiamata più lunga\n");
  Print(max);
  printf("Chiamata più breve\n");
  Print(min);

}

void Media(char *city){
  Call *cur=head;
  int n=0;
  float media=0;

  while(cur){
    if(!strcmp(cur->city, city)){
      media+=cur->durata;
      n++;
    }
    cur=cur->next;
  }
  printf("La media è %.2f", media/n);
}

void PrintAll(char *city){
  Call *cur=head;

  while(cur){
    if(!strcmp(cur->city, city))
      Print(cur);
    cur=cur->next;
  }
}
