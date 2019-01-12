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
    int contNum=0;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j, k, x, y, z;
    int *numeros;
    int num[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    printf("Iniciando... \n\n");
    char fileName[50];
    FILE *f;

    int mais[15] = {5,53,51,4,23,54,42,10,17,41,33,24,13,28,30};
    int menos[15] = {46,20,40,19,57,48,14,15,25,39,9,55,21,22,26};
    int indiferentes[30] = {50,32,2,49,16,52,29,27,34,37,43,44,47,56,1,
                            36,31,6,18,8,12,59,58,38,45,7,3,35,11,60};

    int _mais=0, _menos=0, _ind=0, soma=0;

    memset(fileName, 0, 50);
    strcat(fileName, "DistribuicaoMAIS_MENOS.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    for(x=0;x<7;x++){
        for(y=0;y<7;y++){
            for(z=0;z<7;z++){
                if((x+y+z) == 6){
                    //printf("   %d %d %d   \n", x, y, z);

                    contNum = 0;
                    for(i = 0; i < 1895; i++){
                        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros

                        //printf("analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d \n", i, num[0], num[1], num[2], num[3], num[4], num[5]);
                        //fprintf(f, "analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i, num[0], num[1], num[2], num[3], num[4], num[5]);
                        _mais = 0;
                        _ind = 0;
                        _menos = 0;
                        for(j = 0; j < 6; j++){
                            for(k = 0; k < 15; k++){
                                if(num[j]==mais[k])
                                    _mais++;
                            }
                            for(k = 0; k < 30; k++){
                                if(num[j]==indiferentes[k])
                                    _ind++;
                            }
                            for(k = 0; k < 15; k++){
                                if(num[j]==menos[k])
                                    _menos++;
                            }
                        }
                        if((_mais == x) && (_ind == y) && (_menos == z))
                            contNum++;
                    }
                    printf("%d %d %d - %d vezes\n", x, y, z, contNum);
                    fprintf(f, "%d %d %d - %d vezes\n", x, y, z, contNum);

                    soma+=contNum;
               }
            }
        }
    }
    printf("\n\nsoma: %d", soma);
    free(numeros);
    numeros = NULL;
    fclose(f);
    return 0;
}
