/*  Il programma aggetta come solo argomento il nome del file in sui è salvata
    matrice di numeri. I numeri interi positivi rapresentano l'altitudine, lo zero
    l'assenza di terreno. Scrivere un programma capace di individuare i punti da
    cui è possibile vedere la costa in tutte le direzioni(Massimo di riga e
    colonna).

    letta in imput la seguente matrice

                                0 0 0 1 1 0 0 0
                                0 1 4 3 2 2 0 0
                                1 1 5 2 2 4 1 1
                                1 1 2 2 3 2 1 0
                                0 0 0 2 1 1 0 0
prova
    il programma restituisce le coppie di punti (2,2), (4. 3).
*/

#include <stdio.h>
#include <malloc.h>
#include <stdio_ext.h>
#define X 8
#define Y 5

typedef struct Point{
  int x;
  int y;
  struct Point *next;
} Point;

void Link(Point **head, int i, int j);

int main(int argc, char *argv[]){
  int i, j, Max;
  int map[Y][X];
  Point *cur, *headR=NULL, *headC=NULL;
  FILE *src;

  //conrollo argomento
  if(argc!=2){
    printf("ERRORE\nParametro non valido.");
    return(1);
  }

  //controllo file
  if(!(src=fopen(argv[1], "r"))){
    printf("ERRORE\nImpossibile aprire il file.");
    return(1);
  }

  //lettura da file
  for(i=0;i<Y;i++)
    for(j=0;j<X;j++)
      fscanf(src, "%d", &map[i][j]);

  //stampa matrice
  for(i=0;i<Y;i++){
    for(j=0;j<X;j++)
      printf("%3d", map[i][j]);
    printf("\n");
  }

  //ricerca massimi di riga
  for(i=0;i<Y;i++){
    Max=0;
    for(j=0;j<X;j++)
      if(map[i][j]>Max)
        Max=map[i][j];
    for(j=0;j<X;j++)
      if(Max==map[i][j])
        Link(&headR, i, j);
  }

  //ricerca massimi di colonna
  for(j=0;j<X;j++){
    Max=0;
    for(i=0;i<Y;i++)
      if(map[i][j]>Max)
        Max=map[i][j];
    for(i=0;i<Y;i++)
      if(Max==map[i][j])
        Link(&headC, i, j);
  }


  //Comparazione massimi di riga e colonna
  while(headR){
    cur=headC;
    while(cur){
      if(headR->x==cur->x && headR->y==cur->y)
        printf("(%d, %d)", cur->y, cur->x);
      cur=cur->next;
    }
    headR=headR->next;
  }

 __fpurge(stdin);
 getchar();
}

//Agginta alla lista
void Link(Point **head, int i, int j){
  Point *New=(Point *)malloc(sizeof(Point));
  New->x=j;
  New->y=i;
  New->next=*head;
  *head=New;
}
