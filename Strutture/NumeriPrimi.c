#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, divisore;

    for(i=50; i<100; i++){
        divisore = 0;
        for(n=3; n<i; n++){
            if((2*i+1)%n==0){
                divisore=1;
                break;
            }
        }
     if (divisore == 0)
        printf("Il numero %d è primo.\n", i*2+1);
    }
}
