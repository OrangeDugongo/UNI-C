/*
    Thanks michele zurlo for the base and functions InserisciLibro
    InserisciPrestito  and VerificaPrestito
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct Autore{
  char *nome;
  char *cognome;
}Autore;

typedef struct Libro{
    char *ID;
    char *titolo;
    int autoriN;
    Autore *link;
    struct Libro *next;
}Libro;

typedef struct Data{
  int anno;
  int mese;
  int giorno;
}Data;

typedef struct Prestito{
    char *nome;
    char *cognome;
    char *ID;
    Data inizio;
    Data fine;
    struct Prestito *next;
}Prestito;

void InserisciLibro(char*, char*, int, Autore *);
void InserisciPrestito(char*, char*, char*, Data *);
int VerificaPrestito(char* );
void StampaLibriUtente(char *nome, char *cognome, int mode);//1 per stampare tutto
void CercaPerLibro(char *titolo);

Libro *headLibri;
Prestito *headPrestiti;

int main(int argc, char* argv[]){
    int autoriN, i;
    char id[100];
    char titolo[100];
    char nome[100];
    char cognome[100];
    char buffer[100];
    Data *data= (Data *)malloc(2*sizeof(Data));
    Autore *autore;

    int scelta;
    FILE *dbLibri, *dbPrestiti;

    if(!(dbLibri = fopen("elenco.dat", "r")) || !(dbPrestiti = fopen("prestiti.dat", "r"))){
        printf("Errore nell'apertura del database!\n");
        return 1;
    }

    while(fscanf(dbLibri, "%s", id) != EOF){

        fscanf(dbLibri, "%s", titolo);
        fscanf(dbLibri, "%d", &autoriN);
        autore=(Autore *)malloc(autoriN*sizeof(Autore));

        for(i=0; i<autoriN; i++){
          fgets(buffer, 200, dbLibri);
          autore[i].nome=(char *)calloc(strlen(buffer)+1, sizeof(char));
          strcpy(autore[i].nome, buffer);
          fgets(buffer, 200, dbLibri);
          autore[i].cognome=(char *)calloc(strlen(buffer)+1, sizeof(char));
          strcpy(autore[i].cognome, buffer);
        }

        InserisciLibro(id, titolo, autoriN, autore);
    }


    while(fscanf(dbPrestiti, "%s", nome) != EOF){
        fscanf(dbPrestiti, "%s", cognome);
        fscanf(dbPrestiti, "%s", id);
        for(i=0; i<2; i++){
          fscanf(dbPrestiti, "%d", &data[i].anno);
          fscanf(dbPrestiti, "%d", &data[i].mese);
          fscanf(dbPrestiti, "%d", &data[i].giorno);
        }


        InserisciPrestito(nome, cognome, id, data);
    }

    do{
        printf("----------\n"\
               "Biblioteca\n"\
               "----------\n");

        printf("\n1: Verifica prestito");
        printf("\n2: Cerca libri (in prestito) per utente");
        printf("\n3: Cerca libri (tutti) per utente");
        printf("\n4: Cerca cliente per libro");
        printf("\n5: Esci");
        printf("\n\nDigitare la scelta: ");
        while(scanf("%d", &scelta) <= 0) fflush(stdin);

        switch(scelta){
            case 1:
                printf("Inserisci l'ID del libro: ");
                scanf("%s", id);
                if(!VerificaPrestito(id))
                    printf("\nIl libro e' gia' in prestito o non e' disponibile!\n\n");
                else
                    printf("\nIl libro e' disponibile.\n\n");
                break;

            case 2:
                __fpurge(stdin);
                printf("Inserisci il nome dell'utente: ");
                scanf("%s", nome);
                printf("Inserisci il cognome dell'utente: ");
                scanf("%s", cognome);
                StampaLibriUtente(nome, cognome, 0);
                break;

            case 3:
                __fpurge(stdin);
                printf("Inserisci il nome dell'utente: ");
                scanf("%s", nome);
                printf("Inserisci il cognome dell'utente: ");
                scanf("%s", cognome);
                StampaLibriUtente(nome, cognome, 1);
                break;

            case 4:
                printf("Inserisci il titolo del libro: ");
                scanf("%s", titolo);
                CercaPerLibro(titolo);
                break;

            case 5:
                break;

            default:
                printf("\nLa scelta digitata non e' valida!\n\n");
                break;
        }

    }while(scelta != 5);

    return 0;
}

void InserisciLibro(char* id, char* titolo, int autoriN, Autore *autore){
    struct Libro* cur = headLibri;
    struct Libro* prec = NULL;
    struct Libro* nuovo = (struct Libro*)malloc(sizeof(struct Libro));

    nuovo->ID = (char*)malloc((strlen(id)+1)*sizeof(char));
    nuovo->titolo = (char*)malloc((strlen(titolo)+1)*sizeof(char));

    strcpy(nuovo->ID, id);
    strcpy(nuovo->titolo, titolo);
    nuovo->autoriN = autoriN;
    nuovo->link=autore;


    if(!cur){
        nuovo->next = cur;
        headLibri = nuovo;
    }else{
        while(cur){
            prec = cur;
            cur = cur->next;
        }
        nuovo->next = cur;
        prec->next = nuovo;
    }
}

void InserisciPrestito(char* nome, char* cognome, char* id, Data *data)
{
    struct Prestito* cur = headPrestiti;
    struct Prestito* prec = NULL;
    struct Prestito* nuovo = (struct Prestito*)malloc(sizeof(struct Prestito));

    nuovo->ID = (char*)malloc((strlen(id)+1)*sizeof(char));
    nuovo->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    nuovo->cognome = (char*)malloc((strlen(cognome)+1)*sizeof(char));

    strcpy(nuovo->ID, id);
    strcpy(nuovo->nome, nome);
    strcpy(nuovo->cognome, cognome);
    nuovo->inizio = data[0];
    nuovo->fine = data[1];

    if(!cur){
        nuovo->next = cur;
        headPrestiti = nuovo;
    }
    else{
        while(cur){
            prec = cur;
            cur = cur->next;
        }
        nuovo->next = cur;
        prec->next = nuovo;
    }
}

int VerificaPrestito(char* id){
    struct Prestito* curP = headPrestiti;
    struct Libro* curL = headLibri;
    int esiste=0, disp=1;

    while(curP && disp){
      if(!strcmp(id, curP->ID)){
        esiste=1;
        if(!curP->fine.anno)
          disp = 0;
      }
      curP=curP->next;
    }
    if(!esiste){
      while(curL && !esiste){
        if(!strcmp(id, curL->ID))
          esiste=1;
        curL=curL->next;
      }
    }

    return disp && esiste;
}


void StampaLibriUtente(char *nome, char *cognome, int all){
  Prestito *curP=headPrestiti;
  Libro *curL=NULL;
  int ok=0;

  while(curP){
    if(!strcmp(nome, curP->nome) && !strcmp(cognome, curP->cognome)){
      curL=headLibri;
      while(curL){
        if(!strcmp(curL->ID, curP->ID) && (all || !curP->fine.anno)){
          printf("\n%s", curL->titolo);
          ok=1;
        }
        curL=curL->next;
      }
    }
    curP=curP->next;
  }
  if(!ok){
    printf("\nL'utente non ha ");
    all!=0?printf("preso in prestito "):printf("in prestito ");
    printf("nessun libro.\n");
  }

  putchar('\n');
}

void CercaPerLibro(char *titolo){
  Libro *curL=headLibri;
  Prestito *curP=NULL;
  int ok=0;

  while(curL){
    if(!strcmp(titolo, curL->titolo)){
      curP=headPrestiti;
      while(curP){
        if(!strcmp(curL->ID, curP->ID)){
          printf("\n%s %s", curP->nome, curP->cognome);
          ok=1;
        }
        curP=curP->next;
      }
    }
    curL=curL->next;
  }
  if(!ok)
    printf("\nNessun utente ha preso in prestito il libro");
  printf("\n\n");
}
