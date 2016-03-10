#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10000
#define MAX 4
void Print(int);
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
    }
    for(j=0;j<MAX;j++){
        Print(j);
        printf(": spazi %d, parole %d\n", space[j], space[j]+1);
    }

}

void Print(int j){
    int i;
    for(i=0;i<MAXLINE && str[i]!='\n';i++)
        printf("%c", str[j][i]);
}
