#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, divisore, primo, count;
    count=0;

    for(i=1; i<442; i++){
        divisore = 0;
        for(n=3; n<i; n++){
            if((2*i+1)%n==0){
                divisore=1;
                break;
            }
        }
        if (divisore == 0){
            if (2*i+1==primo+2){
                printf("%d e %d sono due numeri primi gemelli.\n", primo, 2*i+1);
                count++;
            }
            primo = 2*i+1;
        }
    }

    printf("Tra %d e %d ci sono %d numeri primi gemelli.", 1, i*2+1, count);
}
