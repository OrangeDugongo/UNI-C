#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Studente {
    char* cognome;
    int Esami;
    struct Studente* next;
} Studente;

void Inserisci(char*, int);
void InserisciCoda(char*, int);
void Stampa();
void Cerca(char*);
void CercaE(int);
void Inseriscio(char*, int);
void Salva(FILE *);
int Elimina(char *);

Studente *head = NULL;

int main(int argc, char *argv[]){
    int menu, Esami, cEsami;
    char buffer[200];
    char nomef[256];
    FILE *db;

    printf("Quale file vuoi caricare: ");
    scanf("%s", nomef);


    if(!(db = fopen(nomef, "r"))){
        printf("\nIl file da te cercato non esiste. Ora lo creo...\n");
        db = fopen(nomef, "w");
    }else{
        while(fscanf(db, "%s", buffer) != EOF){
            fscanf(db, "%d", &Esami);
            fscanf(db, "%s", nomef);
            Inseriscio(buffer, Esami);
        }
    }

    fclose(db);

    do{
        printf("\n--------");
        printf("\nMenu':\n");
        printf("\n1: Inserisci studente");
        printf("\n2: Inserisci studente in coda");
        printf("\n3: Inserisci studente ordinatamente");
        printf("\n4: Stampa studenti");
        printf("\n5: Cerca studente");
        printf("\n6: Cerca studenti per numero di Esami");
        printf("\n7: Elimina");
        printf("\n8: Salva ed esci");
        printf("\n");
        printf("\nInserisci la scelta: ");
        while(scanf("%d", &menu) <= 0)
          fflush(stdin);

        switch(menu){
            case 1: printf("\nInserisci il cognome: ");
                    scanf("%s", buffer);
                    printf("\nInserisci il numero di Esami: ");
                    scanf("%d", &Esami);
                    Inserisci(buffer, Esami);
               break;

            case 2: printf("\nInserisci il cognome: ");
                    scanf("%s", buffer);
                    printf("\nInserisci il numero di Esami: ");
                    scanf("%d", &Esami);
                    InserisciCoda(buffer, Esami);
                break;

            case 3: printf("\nInserisci il cognome: ");
                    scanf("%s", buffer);
                    printf("\nInserisci il numero di Esami: ");
                    scanf("%d", &Esami);
                    Inseriscio(buffer, Esami);
                break;

            case 4: Stampa();
                break;

            case 5: printf("\nInserisci il cognome da ricercare: ");
                    scanf("%s", buffer);
                    Cerca(buffer);
                break;

            case 6: printf("\nInserisci il numero di Esami: ");
                    scanf("%d", &cEsami);
                    CercaE(cEsami);
                break;

            case 7:printf("\nInserisci il cognome: ");
                   scanf("%s", buffer);
                   printf("\nsono stati eliminati %d elemnti", Elimina(buffer));
                break;

            case 8:
                break;

            default:
                printf("\nIl valore inserito non e' valido!\n");
        }
    }while(menu != 8);

    printf("Su quale file vuoi salvare?: ");
    scanf("%s", nomef);
    db = fopen(nomef, "w");

    Salva(db);

}

int Elimina(char *buffer){
  int n=0;
  Studente *cur=head, *pre=NULL;
  while(cur && strcmp(buffer, cur->cognome)>=0)
    if(!pre && !strcmp(buffer, cur->cognome)){
      head=cur->next;
      free(cur->cognome);
      free(cur);
      n++;
      cur=head;
    }else if(!strcmp(buffer, cur->cognome)){
      pre->next=cur->next;
      free(cur->cognome);
      free(cur);
      n++;
      cur=pre->next;
    }else{
      pre=cur;
      cur=cur->next;
    }
  return(n);
}

void Inserisci(char* buffer, int es){
    Studente* p = (Studente*) malloc(sizeof(Studente));

    p->cognome = (char*) malloc((strlen(buffer)+1)*sizeof(char));

    strcpy(p->cognome, buffer);

    p->Esami = es;

    p->next = head;

    head = p;
}

void InserisciCoda(char* buffer, int es){
    Studente* cur = head;
    Studente* p = (Studente*) malloc(sizeof(Studente));

    p->cognome = (char*) malloc((strlen(buffer)+1)*sizeof(char));

    strcpy(p->cognome, buffer);

    p->Esami = es;

    p->next = NULL;

    if(!cur)
      head = p;
    else{
        while(cur && (cur->next))
            cur = cur->next;

        cur->next = p;
    }
}

void Stampa(){
    Studente *cur = head;

    while(cur){
        printf("\n%s  %d\n", cur->cognome, cur->Esami);
        cur = cur->next;
    }
}

void Cerca(char* cgn){
    Studente* cur = head;

    while(cur && strcmp(cur->cognome, cgn))
      cur = cur->next;

    if(!cur)
      printf("\nStudente non trovato!\n");
    else
      printf("\n%s trovato con %d Esami\n", cur->cognome, cur->Esami);
}

void CercaE(int es){
    Studente* cur = head;

    while(cur){
        if(cur->Esami == es)
            printf("\nTrovato %s\n", cur->cognome);

        cur = cur->next;
    }
}

void Inseriscio(char* buffer, int es){
    Studente *cur = head, *pre = NULL;

    Studente *p = (Studente*) malloc(sizeof(Studente));

    p->cognome = (char*) malloc((strlen(buffer)+1)*sizeof(char));

    strcpy(p->cognome, buffer);

    p->Esami = es;

    p->next = head;

    if(!cur || (strcmp(cur->cognome, buffer)) > 0){
        p->next = head;
        head = p;
    }else{
        while(cur && (strcmp(buffer, cur->cognome)) >= 0){
            pre = cur;
            cur = cur->next;
        }

        pre->next = p;
        p->next = cur;
    }
}

void Salva(FILE *fp){
    Studente *cur = head;

    while(cur){
        fprintf(fp, "%s %d * ", cur->cognome, cur->Esami);
        cur = cur->next;
    }

    fclose(fp);
}
