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
#include <time.h>
#define DIM 4
int Win(int *);
int Giocabile(int mat[DIM][DIM], int);
void Print(int mat[DIM][DIM]);
void Replace(int mat[DIM][DIM], int);
void Genesis(int *p);

int main(){
  int scelta, count=0, mat[DIM][DIM];//={{1,2,3,4},{5,6,7,8},{9,10,15,11},{13,14,16,12}};//test vittoria
  Genesis(mat);
  do{
    Print(mat);
    do{
      printf("Inserisci il numero che vuoi spostare: ");
      scanf("%d", &scelta);
    }while(!Giocabile(mat, scelta));
    count++;
    Replace(mat, scelta);
  }while(!Win(mat));
  printf("\n   You Win!\n");
  Print(mat);
  printf("\nHai completato il puzzle in %d mosse.", count);
}

int Win(int *p){
  int i, ordinata=1;
  for(i=0;i<DIM*DIM-1;i++){
    if(*(p++)>*(p))
      ordinata=0;
  }
  return(ordinata);
}

void Print(int mat[DIM][DIM]){
  int i, j;
  for(i=0;i<DIM;i++){
    for(j=0;j<DIM;j++){
      if(mat[i][j]==16)
        printf("   ");
      else
        printf("%3d", mat[i][j]);
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

void Replace(int mat[DIM][DIM], int scelta){
  int i, j, a_i, a_j, b_i, b_j;
  for(i=0;i<DIM;i++){
    for(j=0;j<DIM;j++){
      if(mat[i][j]==16){
        a_i=i;
        a_j=j;
      }
      if(mat[i][j]==scelta){
        b_i=i;
        b_j=j;
      }
    }
  }
  mat[a_i][a_j]=scelta;
  mat[b_i][b_j]=16;
}

void Genesis(int *p){
  int i, j, ok;
  for(i=0;i<DIM*DIM;i++){
    do{
      ok=1;
      *(p+i)=rand()%16+1;
      for(j=0;j<i && ok==1;j++){
        if(*(p+i)==*(p+j))
          ok=0;
      }
    }while(!ok);
  }
}
