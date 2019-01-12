#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"

/*int totalJogos(){
    char charLinha[51];
    int cont=-1;
    FILE *fp;
    fp = fopen("../include_jogos/sorteios.txt", "r");
    //fp = fopen("sorteios.txt", "r");
    if (!fp){
        printf("Arquivo nao encontrado!");
        exit(0);
    }
    while (!feof(fp)){
       fgets(charLinha, 50, fp);
       cont++;
    }
    fclose(fp);
    return cont;
}*/

int main(int argv, char *argc[])
{
    int contNum;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j, k, QuantDezenas;
    int *numeros;
    char fileName[50], fcat[4];
    int num[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    int jogo[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    FILE *f;

    memset(jogo, 0, 15);

    printf("\nDigite a quantidade de dezenas(entre 1 e 15): ");
    scanf("%d", &QuantDezenas);
    if ((QuantDezenas<1) && (QuantDezenas>15)) {
        printf("Quantidade de dezenas invalida! - Feche e Abra o Programa novamente!");
        exit(0);
    }
    else{
        putchar('\n');
        for(i = 0;i < QuantDezenas; i++){
            printf("Digite a dezena %02d: ", (i+1));
            scanf("%d", &jogo[i]);
        }
    }

    printf("\nAnalisando as dezenas \"");
    for(i=0;i<QuantDezenas;i++)
        printf("%02d ", jogo[i]);
    printf("\" em todos os jogos da MEGA SENA\n");


    memset(fileName, 0, 50);
    strcat(fileName, "Jogo");
    for(i = 0; i < QuantDezenas; i++){
        sprintf(fcat, "-%02d", jogo[i]);
        strcat(fileName, fcat);
    }

    strcat(fileName, ".txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }

    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);
    for(i = 0; i < (sizeof(jogosMega)/24); i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros
        contNum = 0;
        for(j = 0; j < 6; j++){
            for(k = 0; k < QuantDezenas; k++){
                if(num[j] == jogo[k]){
                    contNum++;
                    break;
                }
            }
        }
        if(contNum == 1) unico++;
        if(contNum == 2) duque++;
        if(contNum == 3) ternos++;
        if(contNum == 4) quadras++;
        if(contNum == 5) quinas++;
        if(contNum == 6) senas++;
        if(contNum >= 3) {
            printf("processando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i+1, num[0], num[1], num[2], num[3], num[4], num[5]);
            fprintf(f, "processando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i+1, num[0], num[1], num[2], num[3], num[4], num[5]);
            printf(" -> Acertou: (%d dezenas) \n", contNum);
            fprintf(f," -> Acertou: (%d dezenas) \n", contNum);
        }
    }

    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    printf("\nSenas: %d, Quinas: %d, Quadras: %d, Ternos: %d, Duques: %d, Uma dezena: %d\n", senas, quinas, quadras, ternos, duque, unico);
    fprintf(f, "\nSenas: %d, Quinas: %d, Quadras: %d, Ternos: %d, Duques: %d, Uma dezena: %d\n", senas, quinas, quadras, ternos, duque, unico);
    printf("------------------------------------------------------------------------\n\n");
    fprintf(f, "------------------------------------------------------------------------\n\n");
    fclose(f);
    free(numeros);
    numeros = NULL;
    system("PAUSE");
    return 0;
}
