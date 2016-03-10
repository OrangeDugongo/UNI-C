#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, fib1, fib2, fib3, i;

    printf("Di quanto lunga vuoi la sequenza? ");
    scanf("%d", &n);

    fib1 =1;
    fib2 =0;
    fib3 =0;

    for(i=0;i<n;i++){
        printf("%d ", fib1);
        fib3 = fib2;
        fib2 = fib1;
        fib1 = fib2 + fib3;

    }
}
