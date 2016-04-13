#include "Esami.c"

// Cerca una corrispondenza tra in itere fornito in ingresso e il dato salvato nel
// campo matricola della struttura studente.
// Restituisce l'indice della struttura in cui è salvato lo studente.
int Search(Studente a[], int mat);


// Restituisce 1 se il numero di matricola è associato ad uno studente
// 0 se il numero di matricola non è associato a nessuno studente.
int Esiste( Studente a[], int mat, int i);


// Restituisce il numero di esami sostenuti da un singolo srudente(identificato dalla matricola)
int Count(int mat, Esame e[]);


// Restuisce la media degli esami sostenuti da un singolo studente(identifivato dalla matricola)
float Media(int mat, Esame e[]);


// Permette di inserire gli studenti nella struttura Studente.
void InserisciAula(Studente a[]);


// Permette di inserire gli esami nella struttura Esami.
void InserisciEsami(Esame e[], Studente a[]);


// Stampa tutti gli studenti presenti nell'aula.
void PrintAula(Studente a[], Esame e[]);


// Stampa un singolo studente.
void PrintStudente(Studente a[], Esame e[]);

// Gestisce il menu.
void Menu(Studente a[], Esame e[], int menu);
