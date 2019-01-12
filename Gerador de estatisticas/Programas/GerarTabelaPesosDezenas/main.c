#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"
#include <time.h>

int main(int argv, char *argc[])
{
    int i, j;
    char fileName[50];
    int vetorPeso[11388];
    int contador=0;
    FILE *f;
    srand(time(NULL));

    memset(fileName, 0, 50);
    strcat(fileName, "OcorrenciasDezenas.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    int numero;
    /*for(i=0;i<5000;i++){
        numero = jogosMega[rand()%sizeof(jogosMega)/24][rand()%6];
        printf("%02d - ", numero);
    }*/
    int valor; int v=30;
    valor = ((float)11)/100*v;
    printf("%d", valor);
    fclose(f);
    return 0;
}
