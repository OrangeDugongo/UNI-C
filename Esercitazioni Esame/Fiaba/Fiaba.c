/*  Scrivere un programma c per identidficare la parola ripetuta più volte all'
    interno di un file di testo.
    - il nome del file viene specificato come primo argomento da line di comando.
    - il numero di caratteri e parole del file non è noto.
    - il file contiene unicamente lettere maiuscole, spazi e new-line.
    - il file di testo è composto da più righe.
    - sono previste al massimo 5000 parole distinte.
    - ogni parola è composta massimo da 20 caratteri.
    - le parole sono separate da uno o più spazi.
    - nel caso in cui le parole ripetute più volte all'interno del testo stampare
      quella che compare prima nel testo.
    - stampare anche il numero di occorenze della parola.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdio_ext.h>
#define MAXSTR 5000
#define MAXCHAR 20

typedef struct Token{
  char *str;
  int n;
  struct Token *next;
} Token;

void Inserimento(Token **head, char *buffer, int *count);

int main(int argc, char *argv[]){
  //Dichiarazione variabili
  FILE *src;
  char buffer[MAXCHAR+1];
  Token *head=NULL, *max=NULL;
  int count=0;

  //Controllo argomento
  if(argc!=2){
    printf("ERRORE\nArgomenti non inseriti correttamente.");
    return(0);
  }

  //Controllo file
  if(!(src=fopen(argv[1], "r"))){
    printf("ERRORE\nImpossibile leggere il file.");
    return(0);
  }

  //Lettura da file
  while(fscanf(src, "%s", buffer) != EOF)
    if(count<=MAXSTR)
      Inserimento(&head, buffer, &count);
    fclose(src);

  //Ricerca elemento
  while(head){
    if(!max || (max->n)<(head->n))
      max=head;
    head=head->next;
  }


  //Stampa
  if(max)
    printf("la parola %s è ripetuta %d volte", max->str, max->n);
  else
    printf("Nessuna occorenza.");

  __fpurge(stdin);
  getchar();
}

void Inserimento(Token **head, char *buffer, int *count){
  Token *cur=*head, *pre=NULL;

  //Scorrimento della lista
  while(cur && strcmp(cur->str, buffer)){
    pre=cur;
    cur=cur->next;
  }

  //Creazzione nuovo elemento
  if(!cur){
    Token *New=(Token *)malloc(sizeof(Token));
    New->str=(char *)calloc(strlen(buffer)+1, sizeof(char));
    strcpy(New->str, buffer);
    New->n=1;
    (*count)++;
    //Inserzione in testa
    if(!pre){
      New->next=*head;
      *head=New;
    //Inserzione in coda
    }else{
      New->next=cur;
      pre->next=New;
    }
  //Aggiornamento occorenze
  }else
    (cur->n)++;

}
