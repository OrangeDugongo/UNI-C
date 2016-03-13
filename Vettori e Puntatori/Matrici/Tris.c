#include <stdio.h>
#define TRIS 3
int t[TRIS][TRIS]={{0,0,0},{0,0,0},{0,0,0}};
void Print();
int Giocabili(int r, int c);
void Mossa(int *r, int *c, int player);
void Replace(int r, int c, int player);

int main(){
  int r, c;
  do{
    Print();
    Mossa(&r, &c, 1);
    Replace(r, c, 1);
    Print();
    Mossa(&r, &c, 2);
    Replace(r, c, 2);
  }while(1);
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
