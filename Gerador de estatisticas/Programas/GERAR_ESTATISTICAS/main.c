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
    strcat(fileName, "../../ESTATISTICAS_MEGA.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);
    totalJogos = (sizeof(jogosMega)/24);
    for(i = 0; i < totalJogos; i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros

        contNum = 0;
        for(j = 0; j < 6; j++){
            if(num[j]<30){
                contNum++;
            }
        }
        if(contNum == 6) senas++;
        if(contNum == 5) quinas++;
        if(contNum == 4) quadras++;
        if(contNum == 3) ternos++;
        if(contNum == 2) duque++;
        if(contNum == 1) unico++;
        if(contNum == 0) nada++;
    }
    printf("------------------- USANDO 30 COMO DIVISOR --------------------------");
    fprintf(f, "------------------- USANDO 30 COMO DIVISOR --------------------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 abaixo e 0 acima - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 abaixo e 0 acima - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 abaixo e 1 acima - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 abaixo e 1 acima - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 abaixo e 2 acima - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 abaixo e 2 acima - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 abaixo e 3 acima - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 abaixo e 3 acima - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 abaixo e 4 acima - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 abaixo e 4 acima - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 abaixo e 5 acima - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 abaixo e 5 acima - %d - %1.2f%%\n", unico, porcent);
    porcent =  ((float) nada/totalJogos*100);
    printf("0 abaixo e 6 acima - %d - %1.2f%%\n", nada, porcent);
    fprintf(f,"0 abaixo e 6 acima - %d - %1.2f%%\n", nada, porcent);
    printf("\n");
    fprintf(f, "\n");
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;

    for(i = 0; i < totalJogos; i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros

        contNum = 0;
        for(j = 0; j < 6; j++){
            if(num[j]%2==0){
                contNum++;
            }
        }
        if(contNum == 6) senas++;
        if(contNum == 5) quinas++;
        if(contNum == 4) quadras++;
        if(contNum == 3) ternos++;
        if(contNum == 2) duque++;
        if(contNum == 1) unico++;
        if(contNum == 0) nada++;
    }
    printf("------------------- DISTRIBUICAO DE PARIDADE --------------------------");
    fprintf(f, "------------------- DISTRIBUICAO DE PARIDADE --------------------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 Pares e 0 Impares - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 Pares e 0 Impares - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 Pares e 1 Impares - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 Pares e 1 Impares - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 Pares e 2 Impares - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 Pares e 2 Impares - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 Pares e 3 Impares - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 Pares e 3 Impares - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 Pares e 4 Impares - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 Pares e 4 Impares - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 Pares e 5 Impares - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 Pares e 5 Impares - %d - %1.2f%%\n", unico, porcent);
    porcent =  ((float) nada/totalJogos*100);
    printf("0 Pares e 6 Impares - %d - %1.2f%%\n", nada, porcent);
    fprintf(f,"0 Pares e 6 Impares - %d - %1.2f%%\n", nada, porcent);
    printf("\n");
    fprintf(f, "\n");
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;


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
            if(contNum>tot) tot = contNum;
        }
        if(tot == 5) senas++;
        if(tot == 4) quinas++;
        if(tot == 3) quadras++;
        if(tot == 2) ternos++;
        if(tot == 1) duque++;
        if(tot == 0) unico++;

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
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;

    int num1[6];
    for(i = 1; i < (totalJogos-1); i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j];
        for(j=0;j<6;j++) num1[j] = jogosMega[i+1][j];

        contNum = 0;
        for(j = 0; j < 6; j++){
            for(k = 0;k < 6;k++){
                if(num1[j]==num[k]){
                    contNum++;
                    break;
                }
            }
        }
        if(contNum == 6) senas++;
        if(contNum == 5) quinas++;
        if(contNum == 4) quadras++;
        if(contNum == 3) ternos++;
        if(contNum == 2) duque++;
        if(contNum == 1) unico++;
        if(contNum == 0) nada++;
    }

    printf("--------- REPETICAO DE DEZENAS DE (UM) JOGO ANTERIOR -------------");
    fprintf(f,"--------- REPETICAO DE DEZENAS DE (UM) JOGO ANTERIOR -------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    porcent =  ((float) nada/totalJogos*100);
    printf("0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    fprintf(f,"0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    printf("\n");
    fprintf(f, "\n");
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;

    int num2[6];
    int ocorr[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(i = 1; i < (totalJogos-2); i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j];
        for(j=0;j<6;j++) num1[j] = jogosMega[i+1][j];
        for(j=0;j<6;j++) num2[j] = jogosMega[i+2][j];

        contNum = 0;
        int tot = 0;
        for(j = 0; j < 6; j++){
            for(k = 0;k < 6;k++){
                if(num2[j]==num1[k]){
                    ocorr[contNum++] = num2[j];
                }
                if(num2[j]==num[k]){
                    ocorr[contNum++] = num2[j];
                }
            }
        }

        for(j = 0; j < contNum; j++){
            for(k = j; k < contNum; k++){
                if(ocorr[j] == ocorr[k])
                    ocorr[k] == 0;
            }
        }

        for(j = 0; j<contNum;j++){
            if(ocorr[j] != 0)
                tot++;
        }
        if(contNum == 6) senas++;
        if(contNum == 5) quinas++;
        if(contNum == 4) quadras++;
        if(contNum == 3) ternos++;
        if(contNum == 2) duque++;
        if(contNum == 1) unico++;
        if(contNum == 0) nada++;
    }

    printf("--------- REPETICAO DE DEZENAS DE (DOIS) JOGOS ANTERIORES -------------");
    fprintf(f,"--------- REPETICAO DE DEZENAS DE (DOIS) JOGOS ANTERIORES -------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    porcent =  ((float) nada/totalJogos*100);
    printf("0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    fprintf(f,"0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    printf("\n");
    fprintf(f, "\n");
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;

    int num3[6];
    for(i = 1; i < (totalJogos-3); i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j];
        for(j=0;j<6;j++) num1[j] = jogosMega[i+1][j];
        for(j=0;j<6;j++) num2[j] = jogosMega[i+2][j];
        for(j=0;j<6;j++) num3[j] = jogosMega[i+3][j];

        contNum = 0;
        int tot = 0;
        for(j = 0; j < 6; j++){
            for(k = 0;k < 6;k++){
                if(num3[j]==num2[k]){
                    ocorr[contNum++] = num3[j];
                }
                if(num3[j]==num1[k]){
                    ocorr[contNum++] = num3[j];
                }
                if(num3[j]==num[k]){
                    ocorr[contNum++] = num3[j];
                }
            }
        }

        for(j = 0; j < contNum; j++){
            for(k = j; k < contNum; k++){
                if(ocorr[j] == ocorr[k])
                    ocorr[k] == 0;
            }
        }

        for(j = 0; j<contNum;j++){
            if(ocorr[j] != 0)
                tot++;
        }
        if(contNum == 6) senas++;
        if(contNum == 5) quinas++;
        if(contNum == 4) quadras++;
        if(contNum == 3) ternos++;
        if(contNum == 2) duque++;
        if(contNum == 1) unico++;
        if(contNum == 0) nada++;
    }

    printf("--------- REPETICAO DE DEZENAS DE (TRES) JOGOS ANTERIORES -------------");
    fprintf(f,"--------- REPETICAO DE DEZENAS DE (TRES) JOGOS ANTERIORES -------------");
    porcent =  ((float) senas/totalJogos*100);
    printf("\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    fprintf(f,"\n6 Dezenas - %d - %1.2f%%\n", senas, porcent);
    porcent =  ((float) quinas/totalJogos*100);
    printf("5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    fprintf(f,"5 Dezenas - %d - %1.2f%%\n", quinas, porcent);
    porcent =  ((float) quadras/totalJogos*100);
    printf("4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    fprintf(f,"4 Dezenas - %d - %1.2f%%\n", quadras, porcent);
    porcent =  ((float) ternos/totalJogos*100);
    printf("3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    fprintf(f,"3 Dezenas - %d - %1.2f%%\n", ternos, porcent);
    porcent =  ((float) duque/totalJogos*100);
    printf("2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    fprintf(f,"2 Dezenas - %d - %1.2f%%\n", duque, porcent);
    porcent =  ((float) unico/totalJogos*100);
    printf("1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    fprintf(f,"1 Dezenas - %d - %1.2f%%\n", unico, porcent);
    porcent =  ((float) nada/totalJogos*100);
    printf("0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    fprintf(f,"0 Dezenas - %d - %1.2f%%\n", nada, porcent);
    printf("\n");
    fprintf(f, "\n");
    contNum = quinas = quadras = ternos = senas = duque = unico = nada = 0;



    printf("-------------- DICAS DIVERSAS -----------------------------------------\n");
    fprintf(f,"-------------- DICAS DIVERSAS -----------------------------------------\n");
    printf("Jogos comecando nos 20\n\n");
    fprintf(f,"Jogos comecando nos 20\n\n");

    printf("73,2%% --- acontece pelo menos uma das unidades\n");
    fprintf(f,"73,2%% --- acontece pelo menos uma das unidades\n");
    printf("26,8%% --- nao ocorre\n");
    fprintf(f,"26,8%% --- nao ocorre\n");
    printf("-----------------------------------------------------------------------\n");
    fprintf(f,"--------------------------------------------------------------------\n");
    printf("3 dezenas na casa dos 20\n");
    fprintf(f,"3 dezenas na casa dos 20\n");
    printf("repete um ou duas na casa dos 20\n");
    fprintf(f,"repete um ou duas na casa dos 20\n");
    printf("-----------------------------------------------------------------------\n");
    fprintf(f,"--------------------------------------------------------------------\n");


    printf("\n\ntotal = %d", totalJogos);
    fclose(f);
    return 0;
}
