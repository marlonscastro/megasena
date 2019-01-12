#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"


int main(int argv, char *argc[])
{
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j;
    int num[6] = {0,0,0,0,0,0};
    printf("Iniciando... \n\n");
    char fileName[50];
    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "ArrayTodosOsJogosAte1894.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    for(i = 0; i < 1894; i++){
        for(j=0;j<6;j++) num[j] = jogosMega[i][j];

        printf("analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d\n", (i+1), num[0], num[1], num[2], num[3], num[4], num[5]);
        fprintf(f, "{%d, %d, %d, %d, %d, %d},\n", num[0], num[1], num[2], num[3], num[4], num[5]);
    }
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    printf("\n 6:%d - 5:%d - 4:%d - 3:%d - 2:%d - 1:%d \n", senas, quinas, quadras, ternos, duque, unico);
    fprintf(f, "\n 6:%d - 5:%d - 4:%d - 3:%d - 2:%d - 1:%d \n", senas, quinas, quadras, ternos, duque, unico);
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    fclose(f);
    return 0;
}
