#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct Posto{
    char *cognome;
    int colonna;
    struct Posto *next;
}Posto;

typedef struct Riga{
    int riga;
    Posto *link;
    struct Riga *next;
}Riga;

void Prenota(char *, int, int);
void Colonna(int, char *, Posto **);
void Print();

struct Riga *head=NULL;

int main() {
    int i, n, riga, col;
    char buffer[200];
    srand(time(NULL));

    printf("Quanti spattatori vuoi prenotare: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Cognome utente %d: ", i+1);
        scanf("%s", buffer);
        riga=rand()%15;
        col=rand()%20;

        Prenota(buffer, riga, col);
    }
    Print();
    __fpurge(stdin);
    getchar();
}


void Prenota(char* cognome, int riga, int col) {  /* l'inserzione sar� ordinata ma non ci sono ripetizioni */
    Riga *cur=head;
    Riga *prec=NULL;

    if(!cur || cur->riga > riga) {
        Riga *New=(Riga *)malloc(sizeof(Riga));

        New->riga=riga;
        New->link=(Posto *)malloc(sizeof(Posto));
        New->link->colonna=col;
        New->link->next=NULL;
        New->link->cognome=(char *)calloc(strlen(cognome)+1, sizeof(char));
        strcpy(New->link->cognome, cognome);

        New->next=head;
        head=New;
    }else {
        while(cur && cur->riga < riga){
            prec=cur;
            cur=cur->next;
        }

        if(!cur || cur->riga != riga) {
          Riga *New=(Riga *)malloc(sizeof(Riga));

          New->riga=riga;
          New->link=(Posto *)malloc(sizeof(Posto));
          New->link->colonna=col;
          New->link->next=NULL;
          New->link->cognome=(char *)calloc(strlen(cognome)+1, sizeof(char));
          strcpy(New->link->cognome, cognome);

          New->next=cur;
          prec->next=New;
        }else
          Colonna(col, cognome, &(cur->link));
    }
}

void Colonna(int col, char *nome, Posto **headP){
  Posto *cur=*headP, *pre=NULL;
  while(!cur && col>cur->colonna){
    pre=cur;
    cur=cur->next;
  }
  Posto *New=(Posto *)malloc(sizeof(Posto));
  New->colonna=col;
  New->cognome=(char *)calloc(strlen(nome)+1, sizeof(char));
  strcpy(New->cognome, nome);

  if(!pre && col!=cur->colonna){
    New->next=*headP;
    *headP=New;
  }else if(pre){
    New->next=cur;
    pre->next=New;
  }
}

void Print(){
  Riga *cur=head, *pre=NULL;
  printf("\n");
  while(cur){
    printf("RIGA %d\n", cur->riga+1);
    Posto *curP=cur->link, *preP=NULL;
    while(curP){
      printf("Posto %d: %s\n", curP->colonna+1, curP->cognome);
      preP=curP;
      curP=curP->next;
    }
    printf("\n\n");
    pre=cur;
    cur=cur->next;
  }
}
