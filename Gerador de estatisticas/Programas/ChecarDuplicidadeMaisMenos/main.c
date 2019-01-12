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
        printf("Arquivo nao encontrado!");
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
    jogo = (char **)malloc(70*sizeof(char));
    if(jogo == NULL)
    {
        printf("erro ao alocar memoria para ponteiro jogo");
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
    int contNum=0, cont2=0, cont3=0;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j, k, x, y, z;
    int *numeros;
    int num[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    printf("Iniciando... \n\n");
    char fileName[50];
    FILE *f;

    int distribuicao[60] = {5,53,51,4,23,54,42,10,17,41,33,24,13,28,30,
                            46,20,40,19,57,48,14,15,25,39,9,55,21,22,26,
                            50,32,2,49,16,52,29,27,34,37,43,44,47,56,1,
                            36,31,6,18,8,12,59,58,38,45,7,3,35,11,60};

    int _mais=0, _menos=0, _ind=0, soma=0;

    memset(fileName, 0, 50);
    strcat(fileName, "Duplicidade_MAIS_MENOS.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    //for(i = 0; i < (sizeof(jogosMega)/6/4); i++){
    for(i = 0; i < (sizeof(jogosMega)/24); i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j];
        cont2=0;
        cont3=0;
        printf("-- jogo: %04d -> ", i+1);
        fprintf(f, "-- jogo: %04d -> ", i+1);
        for(j = 0; j < 60; j+=5){
            contNum = 0;
            for(k = 0; k < 6; k++){
                for(x = 0; x < 5; x++){
                    if(num[k] == distribuicao[j+x]){
                        contNum++;
                        //printf("num[%d] == distribuicao[%d] -> contNum = %d\n", k, (j+x), contNum);
                       //printf(f,"num[%d] == distribuicao[%d] -> contNum = %d\n", k, (j+x), contNum);
                    }
                }

            }
            if(contNum == 2){
                break;
                break;
            }
            if(contNum == 3){
                break;
                break;
            }
            //printf("%d \n", j);
        }
        printf("contNum = %d\n", contNum);
        fprintf(f, "contNum = %d\n", contNum);
        if(contNum == 2) duque++;
        if(contNum <= 1) unico++;
        if(contNum == 3) ternos++;
    }
    printf("\n Tres :%d Duas :%d Uma :%d \n", ternos, duque, unico);
    fprintf(f, "\n  Tres :%d Duas :%d Uma :%d \n", ternos, duque, unico);
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    fclose(f);
    return 0;
}
