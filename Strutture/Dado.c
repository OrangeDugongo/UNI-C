#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    srand(time(NULL));

    for (i=1; i<=200; i++){
        n = rand()%6 +1;
        i%5==0? printf("Risultato lancio %d: 6\n", i): printf("Risultato lancio %d: %d\n", i, n);
    }

}
