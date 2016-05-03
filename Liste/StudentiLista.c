#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Studente {
    char* Cognome;
    int Esami;
    struct Studente* link;
};

void Inserisci(char*, int);
void InserisciCoda(char*, int);
void Stampa();
void Cerca(char*);
void CercaE(int);
void Inseriscio(char*, int);
void Salva(FILE *);

struct Studente* lista_s = NULL;

int main(int argc, char* argv[])
{
    int menu, esami, cesami;
    char buffer[200];
    char nomef[256];
    FILE *db;

    printf("Quale file vuoi caricare?: ");
    scanf("%s", nomef);

    db = fopen(nomef, "r");
    if(!db)
    {
        printf("\nIl file da te cercato non esiste. Ora lo creo...\n");
        db = fopen(nomef, "w");
    }
    else
    {
        while(fscanf(db, "%s", buffer) != EOF)
        {
            fscanf(db, "%d", &esami);
            fscanf(db, "%s", &nomef);
            Inseriscio(buffer, esami);
        }
    }

    fclose(db);

    do
    {
        printf("\n--------");
        printf("\nMenu':\n");
        printf("\n1: Inserisci studente");
        printf("\n2: Inserisci studente in coda");
        printf("\n3: Inserisci studente ordinatamente");
        printf("\n4: Stampa studenti");
        printf("\n5: Cerca studente");
        printf("\n6: Cerca studenti per numero di esami");
        printf("\n7: Salva ed esci");
        printf("\n");
        printf("\nInserisci la scelta: ");
        while(scanf("%d", &menu) <= 0) fflush(stdin);

        switch(menu)
        {
            case 1:
                printf("\nInserisci il cognome: ");
                scanf("%s", buffer);
                printf("\nInserisci il numero di esami: ");
                scanf("%d", &esami);
                Inserisci(buffer, esami);
                break;

            case 2:
                printf("\nInserisci il cognome: ");
                scanf("%s", buffer);
                printf("\nInserisci il numero di esami: ");
                scanf("%d", &esami);
                InserisciCoda(buffer, esami);
                break;

            case 3:
                printf("\nInserisci il cognome: ");
                scanf("%s", buffer);
                printf("\nInserisci il numero di esami: ");
                scanf("%d", &esami);
                Inseriscio(buffer, esami);
                break;

            case 4:
                Stampa();
                break;

            case 5:
                printf("\nInserisci il cognome da ricercare: ");
                scanf("%s", buffer);
                Cerca(buffer);
                break;

            case 6:
                printf("\nInserisci il numero di esami: ");
                scanf("%d", &cesami);
                CercaE(cesami);
                break;

            case 7:
                break;

            default:
                printf("\nIl valore inserito non e' valido!\n");
        }
    } while(menu != 7);

    printf("Su quale file vuoi salvare?: ");
    scanf("%s", nomef);
    db = fopen(nomef, "w");

    Salva(db);

}

void Inserisci(char* buff, int es)
{
    struct Studente* p = (struct Studente*) malloc(sizeof(struct Studente));

    p->Cognome = (char*) malloc((strlen(buff)+1)*sizeof(char));

    strcpy(p->Cognome, buff);

    p->Esami = es;

    p->link = lista_s;

    lista_s = p;
}

void InserisciCoda(char* buff, int es)
{
    struct Studente* cur = lista_s;
    struct Studente* p = (struct Studente*) malloc(sizeof(struct Studente));

    p->Cognome = (char*) malloc((strlen(buff)+1)*sizeof(char));

    strcpy(p->Cognome, buff);

    p->Esami = es;

    p->link = NULL;

    if(!cur) lista_s = p;
    else
    {
        while(cur && (cur->link))
        {
            cur = cur->link;
        }

        cur->link = p;
    }
}

void Stampa()
{
    struct Studente* cur = lista_s;

    while(cur)
    {
        printf("\n%s  %d\n", cur->Cognome, cur->Esami);
        cur = cur->link;
    }
}

void Cerca(char* cgn)
{
    struct Studente* cur = lista_s;

    while(cur && strcmp(cur->Cognome, cgn))
    {
        cur = cur->link;
    }

    if(!cur) printf("\nStudente non trovato!\n");
    else printf("\n%s trovato con %d esami\n", cur->Cognome, cur->Esami);
}

void CercaE(int es)
{
    struct Studente* cur = lista_s;

    while(cur)
    {
        if(cur->Esami == es)
        {
            printf("\nTrovato %s\n", cur->Cognome);
        }
        cur = cur->link;
    }
}

void Inseriscio(char* buff, int es)
{
    struct Studente* cur = lista_s;
    struct Studente* prec = NULL;

    struct Studente* p = (struct Studente*) malloc(sizeof(struct Studente));

    p->Cognome = (char*) malloc((strlen(buff)+1)*sizeof(char));

    strcpy(p->Cognome, buff);

    p->Esami = es;

    p->link = lista_s;

    if(!cur || (strcmp(cur->Cognome, buff)) > 0)
    {
        p->link = lista_s;
        lista_s = p;
    }

    else
    {
        while(cur && (strcmp(buff, cur->Cognome)) >= 0)
        {
            prec = cur;
            cur = cur->link;
        }

        prec->link = p;
        p->link = cur;
    }
}

void Salva(FILE *fp)
{
    struct Studente* cur = lista_s;

    while(cur)
    {
        fprintf(fp, "%s\n%d\n*\n", cur->Cognome, cur->Esami);
        cur = cur->link;
    }

    fclose(fp);
}
