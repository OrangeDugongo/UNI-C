#include <stdio.h>
#include <stdlib.h>
void Swap(int *, int *);
void SwapInutile(int, int);

int main(){
    int x=3, y=5;
    Swap(&x, &y);
    printf("x=%d.....y=%d", x, y);

}

void Swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void SwapInutile(int a, int b) {
  int temp=a;
  a=b;
  b=temp;
}
