#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char frase[], char separador)
{
    int i, j, k, contsep = 0;

     for(i=0,contsep=0;i<strlen(frase);i++)
       if(frase[i] == separador)
          contsep++;

    char  aux[contsep][20];
    char **result = (char**)malloc(contsep*sizeof(char));

    if(contsep)
    {
        for(i=0; i<=contsep; i++ )
          *(result + i) = (char*)malloc(40*sizeof(char));

        for(i=0,k=0,j=0; i < strlen(frase); i++)
           if(frase[i] != separador)
           {
              aux[k][j] = frase[i];
              j++;
           }
           else
           {
              aux[k][j] = 0;
              k++;
              j=0;
           }
        aux[k][j] = 0;

        for(i=0;i<=contsep;i++)
          *(result+i) = strcpy(*(result+i), aux[i]);

        return result;
    }
    else{
        printf("Nenhum Separador Encontrado");
        return NULL;
    }
}

int main()
{
    int **vetor;
    vetor = (int **) malloc(10*(sizeof(int)));
    *(vetor[0]) = 3;
    printf("%d\n", *vetor[0]);

    int i;
    char **jogo;
    char str[60];

    jogo[0] = (char *) malloc(10*sizeof(char));
    jogo[1] = (char *) malloc(10*sizeof(char));
    jogo[2] = (char *) malloc(10*sizeof(char));
    jogo[3] = (char *) malloc(10*sizeof(char));

    strcpy(str,"Marlon.Rossana.Vivian.Melinda");
    jogo = split(str, '.');



    //strcpy(jogo[0], "Marlon");
    printf("%s \n%s \n%s \n%s \n", jogo[0], jogo[3], jogo[2], jogo[1]);

    return 0;
}
