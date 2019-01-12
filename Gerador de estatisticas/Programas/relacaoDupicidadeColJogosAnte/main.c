#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"

int main(int argv, char *argc[])
{
    int contNum;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0, nada=0;
    int i, j, k, totalJogos;
    float porcent;
    int num[6];
    printf("Iniciando... \n\n");
    char fileName[50];
    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "ColunasRelat.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);
    totalJogos = (sizeof(jogosMega)/24);
    int dois = 0, qtdDois = 0;
    for(i = 0; i < totalJogos; i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros

        int tot = 0;
        for(j = 0; j < 6; j++){
            contNum = 0;
            for(k = j+1; k < 6; k++){
                if((num[j]%10==num[k]%10)&&(num[j]!=-1)){
                    contNum++;
                    num[k] = -1;
                }
            }
            if (contNum==1) dois++;
            if (contNum>tot) tot = contNum;
        }
        if(tot == 5) senas++;
        if(tot == 4) quinas++;
        if(tot == 3) {
                quadras++;
                printf("jogo %d\n", i+1);
        }
        if(tot == 2) ternos++;
        if(tot == 1) duque++;
        if(tot == 0) unico++;
        if(dois == 2) qtdDois++;
    }
    printf("------------------- MESMA COLUNA NO VOLANTE --------------------------");
    fprintf(f, "------------------- MESMA COLUNA NO VOLANTE --------------------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 na coluna - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 na coluna - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 na coluna - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 na coluna - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 na coluna - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 na coluna - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 na coluna - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 na coluna - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 na coluna - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 na coluna - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 na coluna - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 na coluna - %d - %1.2f%%\n", unico, porcent);
    printf("\n");
    fprintf(f, "\n");
    printf("Quantidade dois: %d", qtdDois);
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;




    printf("\n\ntotal = %d", totalJogos);
    fclose(f);
    return 0;
}
