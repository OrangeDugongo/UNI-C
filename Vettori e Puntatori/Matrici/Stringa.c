#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10000
#define MAX 4
char str[MAX][MAXLINE];

int main(){
    int i, j, space[MAX]={0,0,0,0};
    char c;
    for(j=0;j<MAX;j++){
        for(i=0;i<MAXLINE && (c = getchar())!='\n' && c!=EOF; i++){
            if (c==' ')
                space[j]++;
            str[j][i]=c;
        }
        str[j][i]="\0";
    }
    for(j=0;j<MAX;j++){
        printf("%s: spazi %d, parole %d\n", str[j], space[j], space[j]+1);
    }

}
