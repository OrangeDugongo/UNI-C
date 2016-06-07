#include <stdio.h>
#include <string.h>
#define INFO 10

typedef struct{
  char str[128];
} String;

int main(){
  char c;
  String info[INFO];
  FILE *string, *diz;
  int mixa=0, i, j, h, r, g, f, e;


  //INSERIMENTO VALORI SUL FILE
  if((string=fopen("string", "w"))){
    printf("Inserisci le informazioni sul sogetto: ");
    do{
      fputc((c=getchar()), string);
    }while(c!=35);
    fclose(string);
  }else{
    printf("Si è verificato un errore.");
		return(0);
	}

  //CONTROLLO SE L'UTENTE HA INSERITO VALORI NEGLI ARRAY
  string=fopen("string", "r");
  do{
    fscanf(string, "%s", info[mixa].str);
  }while (strcmp("#", info[mixa].str) && mixa++<INFO);
  fclose(string);

  //APERTURA FILE
  diz = fopen("dizionario", "w");
  //INIZIO CICLO
  for(i=0;i<mixa;i++){
    //SECONDO CICLO
    for(j=0;j<mixa;j++){
      if(i==j)
        continue;
      fprintf(diz, "%s%s\n", info[i].str, info[j].str);
      //TERZO CICLO
      for(h=0;h<mixa;h++){
        if(i==h || j==h || i==h)
          continue;
        fprintf(diz, "%s%s%s\n", info[i].str, info[j].str, info[h].str);
        //QUARTO CICLO
        for(r=0;r<mixa;r++){
          if(i==h || j==h || i==h || r==i || r==h || r==j)
            continue;
          fprintf(diz, "%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str);
          //QUINTO CICLO
          for(g=0;g<mixa;g++){
            if(i==h || j==h || i==h || r==i || r==h || r==j || g==i || g==j || g==h || g==r)
              continue;
            fprintf(diz, "%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str);
            //SESTO CICLO
            for(f=0;f<mixa;f++){
              if(i==h || j==h || i==h || r==i || r==h || r==j || g==i || g==j || g==h || g==r || f==i || f==j || f==h || f==g || f==r)
                continue;
              fprintf(diz, "%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str);
              //SETTIMO CICLO
              for(e=0;e<mixa;e++){
                if(i==h || j==h || i==h || r==i || r==h || r==j || g==i || g==j || g==h || g==r || f==i || f==j || f==h || f==g || f==r || e==i || e==j || e==g || e==h || e==r || e==f)
                  continue;
                fprintf(diz, "%s%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str, info[e].str);
              }
            }
          }
        }
      }
    }
  }
fclose(diz);
printf("Dizionario creato\n");
__fpurge(stdin);
getchar();
}
