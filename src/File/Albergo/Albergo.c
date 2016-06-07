/*
    Scrivere un programma in grado di leggere da file una lista di alberghi
    comprensiva di prezi e servizi: Il programma dovrà restituire per ogni
    servizio l'albergo con il miglior prezzo.
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <malloc.h>
#include <string.h>

typedef struct albergo{
  char *nome;
  int prezzo;
  int servizi[3];
  struct albergo *next;
} Albergo;

int Read(FILE *src, Albergo **head);
Albergo *Search(Albergo *head, int servizio);

int main(){
  char buffer[21];
  int n;
  Albergo *head=NULL, *best=NULL;
  FILE *src;

  printf("Quale file vuoi aprire: ");
  scanf("%s", buffer);

  if(!(src=fopen(buffer, "r"))){
    printf("ERRORE\nIl file non esiste.");
    return 1;
  }

  if(!Read(src, &head))
    printf("ERRORE\nFile corrotto");
  else{
    do{
      printf("\n1. TV");
      printf("\n2. Condizionatore");
      printf("\n3. Frigo Bar");
      printf("\n0. Exit");
      printf("\nA quale servizio sei interessato: ");
      scanf("%d", &n);

      if(n){
        best=Search(head, n-1);
        printf("\nBEST CHOISE: %s, %d€\n", best->nome, best->prezzo);
      }
    }while(n);
  }

  __fpurge(stdin);
  getchar();
}

int Read(FILE *src, Albergo **head){
  char buffer[21];
  int i;

  while(fscanf(src, "%s", buffer) != EOF){

    //Controllo
    if(!strcasecmp(buffer, "Albergo")){

      fscanf(src, "%s", buffer);
      if(strcasecmp(buffer, "Prezzo"))
        return 0;
      fscanf(src, "%s", buffer);
      if(strcasecmp(buffer, "TV"))
        return 0;
      fscanf(src, "%s", buffer);
      if(strcasecmp(buffer, "Condizionatore"))
        return 0;
      fscanf(src, "%s", buffer);
      if(strcasecmp(buffer, "Frigo"))
        return 0;

    }else{
      Albergo *New=(Albergo *)malloc(sizeof(Albergo));
      New->nome=(char *)calloc(strlen(buffer)+1, sizeof(char));
      strcpy(New->nome, buffer);

      fscanf(src, "%d", &New->prezzo);

      //TV
      for(i=0;i<3;i++){
        fscanf(src, "%s", buffer);
          New->servizi[i]=strcasecmp(buffer, "NO");
      }

      New->next=*head;
      *head=New;
    }
  }
  return 1;
}

Albergo *Search(Albergo *head, int servizio){
  Albergo *min=NULL, *cur=head;
  while(cur){
    if(cur->servizi[servizio] && (!min || cur->prezzo<min->prezzo))
      min=cur;
    cur=cur->next;
  }
  return min;
}
