/**
Si realizzi un programma in linguaggio C che permetta di giocare al gioco del 15. In tale
gioco, una scacchiera 4x4 contiene 15 pezzi (numerati da 1 a 15) ed una casella vuota. Il
giocatore ad ogni mossa può spostare uno dei pezzi adiacenti alla casella vuota nella casella
vuota stessa. Il programma deve avvisare il giocatore quando il gioco è stato risolto (ossia
quando i numeri compaiono nell’ordine numerico corretto).
Il giocatore specifica le proprie mosse indicando il numero del pezzo da spostare nella
casella vuota, come nel seguente esempio:
8   5   2   4
11  1       7
12  10  3   15
9   13  14  6
Le mosse possibili sono: 2, 1, 7, 3. Se il giocatore sceglie la mossa 3, le mosse possibili
diventano: 3, 10, 15, 14
**/
#include <stdio.h>
#define DIM 4
int Win(int *);
int Giocabile(int mat[DIM][DIM], int);
void Print(int mat[DIM][DIM]);
void Replace(int mat[DIM][DIM], int);

int main(){
  int mat[DIM][DIM], scelta;
  do{

    Print(mat);
    do{
      printf("Inserisci il numero che vuoi spostare: ");
      scanf("%d", &scelta);
    }while(!Giocabile(mat, scelta));

  }while(!Win(mat));
}

int Win(int *p){
  int i, ordinata=1;
  for(i=1;i<DIM*DIM;i++){
    if(*p>*(p+i))
      ordinata=0;
  }
  return(ordinata);
}

void Print(int mat[DIM][DIM]){
  int i, j;
  for(i=0;i<DIM;i++){
    for(j=0;j<DIM;j++){
      if(mat[i][j]==16)
        printf(" ");
      else
        printf("%2d", mat[i][j]);
    }
    printf("\n");
  }
}

int Giocabile(int mat[DIM][DIM], int scelta){
  int vet[DIM], giocabile=0, i, j;
  vet[0]=0;
  for(i=0;i<DIM && vet[0]==0;i++){
    for(j=0;j<DIM;j++){
      if(mat[i][j]==16){
        vet[0]=mat[i-1][j];
        vet[1]=mat[i+1][j];
        vet[2]=mat[i][j-1];
        vet[3]=mat[i][j+1];
      }
    }
  }
  if(vet[0]==scelta || vet[1]==scelta || vet[2]==scelta || vet[3]==scelta)
    giocabile=1;
  return(giocabile);
}
