#include <stdio.h>
#include <math.h>
#define TRIS 3
int t[TRIS][TRIS]={{0,0,0},{0,0,0},{0,0,0}};
void Print();
int Giocabili(int r, int c);
void Mossa(int *r, int *c, int player);
void Replace(int r, int c, int player);
void Turno(int r, int c, int player);
int Righe(int *p);
int Colonne(int *p);
int Diagonali(int *p);

int main(){
  int r, c, sum, count=0;

  do{
    Turno(r, c, count++%2+1);
  }while(!Righe(&sum) && !Colonne(&sum) && !Diagonali(&sum));
  
  Print();
  if(sum<0)
    printf("Ha vinto il giocatore 1");
  else
    printf("Ha vinto il giocatore 2");
}

void Print(){
  int i,j;
  for(i=0;i<TRIS;i++){
    for(j=0;j<TRIS;j++){
      if(t[i][j]==-1)
        printf("| X ");
      else if(t[i][j]==1)
        printf("| O ");
      else
        printf("|   ");
    }
    if(i<2)
      printf("|\n-------------\n");
    else
      printf("|\n");
  }
}

int Giocabili(int r, int c){
  int giocabili;
  if(r>=0 && r<3 && c>=0 && c<3){
    if(t[r][c]==0)
      giocabili=1;
    else
      giocabili=0;
  }else
    giocabili=0;
  return(giocabili);
}

void Mossa(int *r, int *c, int player){
  int rr, cc;
  do{
    printf("Giocatore %d, dove vuoi giocare(riga colonna): ", player);
    scanf("%d %d", &rr, &cc);
    *r=rr;
    *c=cc;
  }while(!Giocabili(rr, cc));
}

void Replace(int r, int c, int player){
  if(player==1)
    t[r][c]=-1;
  else
    t[r][c]=1;
}

int Righe(int *p){
  int i, sum, win=0;
  for(i=0;i<3 && win==0;i++){
    sum=t[i][0]+t[i][1]+t[i][2];
    if(abs(sum)==3)
      win=1;
  }
  *p=sum;
  return(win);
}

int Colonne(int *p){
  int i, sum, win=0;
  for(i=0;i<3 && win==0;i++){
    sum=t[0][i]+t[1][i]+t[2][i];
    if(abs(sum)==3)
      win=1;
  }
  *p=sum;
  return(win);
}

int Diagonali(int *p){
  int sum, win=0;
  sum=t[0][0]+t[1][1]+t[2][2];
  if(abs(sum)==3)
    win=1;
  else{
    sum=t[2][0]+t[1][1]+t[0][2];
    if(abs(sum)==3)
      win=1;
  }
  *p=sum;
  return(win);
}

void Turno(int r, int c, int player){
  Print();
  Mossa(&r, &c, player);
  Replace(r, c, player);
}
