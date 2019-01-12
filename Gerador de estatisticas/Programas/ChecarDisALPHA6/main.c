#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"


int vetor[6];
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
char *getSorteio(int linha){
    char *result, charLinha[51];
    int i=0;
    FILE *fp;
    result = (char *) malloc(50 * sizeof(char));
    fp = fopen("../include_jogos/sorteios.txt", "r");
    if (!fp){
        printf("Arquivo de Sorteios nao encontrado!");
        exit(0);
    }
    while (!feof(fp)){
       result = fgets(charLinha, 50, fp);
       if(result){
         if (i == (linha-1)) break;
       }
       i++;
    }
    fclose(fp);
    return result;
}
int* getNumerosMega(int sorteio){   // Retorna um array de inteiros do sorteio passado no argumento
    int i;
    char **jogo; //, *numSorteio;
    char msg[30];
    /*numSorteio = (char *) malloc(50*sizeof(char));
    numSorteio = getSorteio(sorteio);*/
    strcpy(msg, getSorteio(sorteio));
    jogo = (char **) malloc(50*sizeof(char));
    //for(i=0;i<50;i++)
    //    jogo[i] = (char *) malloc(3*sizeof(char));
    if(jogo == NULL)
    {
        printf("erro ao alocar memoria para ponteiro -> jogo");
        exit(0);
    }
    jogo = (char **) split(msg, 9);
    for(i = 0; i < 6; i++){
        vetor[i] = atoi(jogo[i+1]);
    }
    free(jogo);
//    free(numSorteio);
    jogo = NULL;
//    numSorteio = NULL;
    return vetor;
}
int main(int argv, char *argc[])
{
    int contNum;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j, k;
    int *numeros;
    int num[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    printf("Iniciando... \n\n");
    char fileName[50], dezenas[6] = {' ',' ',' ',' ',' ','.'};
    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "ChecarDistribuicaoALPHA6.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    for(i = 0; i < (sizeof(jogosMega)/6/4); i++){
        //numeros = getNumerosMega(i);
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros

        contNum = 0;
        //for(j=0;j<6;j++) dezenas[j] = ' ';

        //for(j=0;j<6;j++){
            if(num[0]>0 && num[0]<10 && dezenas[0]!=' '){
                contNum++;
            }
            if(num[1]>=10 && num[1]<20 && dezenas[1]!=' '){
                contNum++;
            }
            if(num[2]>=10 && num[2]<20 && dezenas[2]!=' '){
                contNum++;
            }
            if(num[3]>=50 && num[3]<=60 && dezenas[3]!=' '){
                contNum++;
            }
            if(num[4]>=50 && num[4]<=60 && dezenas[4]!=' '){
                contNum++;
            }
            if(num[5]>=20 && num[5]<30 && dezenas[5]!=' '){
                contNum++;
            }
        //}

        if(contNum == 1) {
            printf("analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d -- ", i+1, num[0], num[1], num[2], num[3], num[4], num[5]);
            fprintf(f, "analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d -- ", i+1, num[0], num[1], num[2], num[3], num[4], num[5]);
            senas++;
            printf("OK \n");
            fprintf(f, "OK \n");
        }
    }
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    printf("\n Quantidade :%d \n", senas);
    fprintf(f, "\n Quantidade :%d \n", senas);
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    free(numeros);
    numeros = NULL;
    fclose(f);
    return 0;
}
