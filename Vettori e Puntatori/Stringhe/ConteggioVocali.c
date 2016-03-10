#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
const int MAX = 80;

int main(){
    char c , str[MAX];
    int i, vocali=0, consonanti;

    for(i=0;i<MAX-1 && (str[i]=getchar())!='\n';i++){
        if((c=tolower(str[i]))=='a' || c=='e' || c=='i' || c=='o' || c=='u')
          vocali++;
        else if (isalpha(c))
          consonanti++;
    }

    str[i]='\0';

	printf("Nella frase \"%s\" sono presenti %d vocali e %d consonanti.", str, vocali, consonanti);
}
