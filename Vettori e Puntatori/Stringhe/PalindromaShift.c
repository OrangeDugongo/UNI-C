/* Scrivere un programma che determina se una stringa di caratteri allocata dinamicamente è palindroma.
Se la stringa è palindroma, il programma deve poi provvedere a raddoppiare le sole vocali presenti.

Esempio: la stringa "pottop" deve diventare "poottoop" */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

int Palindroma (char *);

int main () {
  char *buffer=(char *)malloc(200*sizeof(char));
  char c;
  unsigned int i, j;

  printf("inserisci la stringa:  ");
  scanf("%s", buffer);
  buffer=(char *) realloc (buffer, (strlen(buffer)+1)*sizeof(char));

  if (Palindroma(buffer))
    for(i=0; i<strlen(buffer); i++)
      if((c=tolower (buffer[i]))=='a' || c== 'e' || c== 'i' || c== 'o' || c== 'u') {
        buffer=(char *)realloc(buffer, (strlen (buffer)+2)*sizeof(char));

        for(j=strlen (buffer); j>=i; j--)
          buffer[j+1]=buffer[j];

        i++;
      }

  printf("\n%s", buffer);
  __fpurge(stdin);
  getchar();
}

int Palindroma(char *buff) {
  unsigned int i;
  int ok=1;

  for(i=0; i<strlen(buff)/2 && ok; i++)
    if(buff[i] != buff[strlen(buff)-1-i])
      ok=0;

  return ok;
}
