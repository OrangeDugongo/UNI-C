#include <stdio.h>
#define N 3
#define M 4

/*typedef struct{
  char *partita[4];
  char *riposo;
}*/
int main(){
  FILE *src, *dest;
  int i, j, casa, trasferta, g;
  char s1[40], s2[40];
  src=fopen("src", "r");
  dest=fopen("dest", "w");

  printf("Che giornata ti interessa: ");
  scanf("%d", &g);

  for(i=0;i<N;i++){
    if(g-1==i)
      fprintf(dest, "Giornata %d\n\n", i+1);
    for(j=0;j<M;j++){
      fscanf(src, "%s %s %d %d", s1, s2, &casa, &trasferta);
      if(g-1==i)
        fprintf(dest, "%s %s %d-%d\n", s1, s2, casa, trasferta);
    }
    fscanf(src, "%s", s1);
    if(g-1==i)
      fprintf(dest, "Riposa %s", s1);
  }

  fclose(src);
  fclose(dest);
}
