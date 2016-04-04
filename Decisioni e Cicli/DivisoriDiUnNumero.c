#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, divisori;

    for(i=1; i<100000000; i++){
        divisori = 0;
        for(n=1; n<i; n++){
            if(i%n==0){
                divisori = divisori+n;
            }
        }
     if (divisori == i)
        printf("Il numero %d è perfetto.\n", i);
    }
}

