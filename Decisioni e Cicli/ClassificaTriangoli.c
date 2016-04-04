#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Controllo(float, float, float);
void Class(float, float, float);

int main()
{
    float a, b, c;

    do{
        printf("Inserisci il lato a: ");
        scanf("%f", &a);
        printf("Inserisci il lato b: ");
        scanf("%f", &b);
        printf("Inserisci il lato c: ");
        scanf("%f", &c);
    }
    while(Controllo(a,b,c)!=1);

    Class(a,b,c);

}

int Controllo(float a, float b, float c){
    if(a>0 && b>0 && c>0 && a+b>c && b+c>a && a+c>b)
        return(1);
}

void Class(float a, float b, float c){
    if(a==b && b==c)
        printf("Il triangolo è equilatero.\n");
    else if(a==b || b==c || a==c){
        if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a)
            printf("Il triangolo è isoscele-rettangolo.\n");
        else
            printf("Il triangolo è isoscele.\n");
    }else{
        if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a)
            printf("Il triangolo è rettangolo.\n");
        else
            printf("Il triangolo è scaleno.\n");
    }
}

/*

void Scaleno(float a, float b, float c){
    if(a!=b && a!=c && c!=b)
        printf("Il triangolo è scaleno.\n");
}

int Rett(float a, float b, float c){
    if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a)
        printf("Il triangolo è rettangolo.\n");
}
*/
