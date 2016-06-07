#include <stdio.h>
const int DIM=10;
//int count=0;
void Riempimento(int *p);
void Print(int *p);
int Swap(int *a);
void Ordinamento(int *p);

int main(){
  int vet[DIM];
  srand(time(NULL));
  Riempimento(vet);
  Print(vet);
  Ordinamento(vet);
  Print(vet);
  //printf("%d", count);
  getchar();
}

void Riempimento(int *p){
  int i, j, ok;

  for(i=0;i<DIM;i++)
    do{
     *(p+i)=rand()%25;
     ok=1;
     for(j=0;j<i && ok;j++)
      if(*(p+i)==*(p+j))
        ok=0;
    }while(!ok);
}

void Print(int *p){
  int i;

  for(i=0;i<DIM;i++)
    printf("%4d", *(p+i));
  printf("\n");
}

int Swap(int *a){
  int temp;

  temp=*a;
  *a=*(a+1);
  *(a+1)=temp;
  return(0);
}

void Ordinamento(int *p){
  int i, j, ok;
  j=DIM-1;

  do{
    ok=1;
    for(i=0;i<j;i++)
      if(*(p+i)>*(p+i+1))
        ok=Swap(p+i);
    //count++;
  }while(--j>1 && !ok);
}
