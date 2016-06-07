#include <stdio.h>
#include <math.h>

//strutture
struct point{
  float x;
  float y;
};

struct rettangolo{
  struct point AD;
  struct point BS;
};
//Prototipi
float Perimetro(struct rettangolo rt);
float Area(struct rettangolo rt);
int Controllo(struct rettangolo rt);

int main(){
  struct rettangolo rt;
  printf("Inserisci le cordinate del punto in alto a destra(x e y): ");
  scanf("%f %f", &rt.AD.x, &rt.AD.y);
  printf("Inserisci le cordinate del punto in basso a sinistra(x e y): ");
  scanf("%f %f", &rt.BS.x, &rt.BS.y);
  if(Controllo(rt)){
    printf("Il perimetro vale: %.2f", Perimetro(rt));
    printf("\nL'area vale: %.2f", Area(rt));
  }else
    printf("I punti inseriti non formano un rettangolo.");

  __fpurge(stdin);
  getchar();
}

int Controllo(struct rettangolo rt){
  if(rt.AD.x==rt.BS.x || rt.AD.y==rt.BS.y)
    return(0);
  return(1);
}

float Perimetro(struct rettangolo rt){
  return((rt.AD.x-rt.BS.x+rt.AD.y-rt.BS.y)*2);
}

float Area(struct rettangolo rt){
  return((rt.AD.x-rt.BS.x)*(rt.AD.y-rt.BS.y));
}
