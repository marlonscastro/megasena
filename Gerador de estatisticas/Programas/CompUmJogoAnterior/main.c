#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int contNum;
    int quadras=0, quinas=0, senas=0, ternos=0, duque=0, unico=0;
    int i, j, k;
    int *numeros;
    int num[6] = {0,0,0,0,0,0}, num2[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    printf("Iniciando... \n\n");
    char fileName[50];
    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "CompCJogoAnterior.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    for(i = 1; i <= 1889; i++){
        numeros = getNumerosMega(i);
        for(j=0;j<6;j++) num[j] = numeros[j]; // n�o se compara valores inteiros com inteiros provenientes de ponteiros
        numeros = getNumerosMega(i+1);
        for(j=0;j<6;j++) num2[j] = numeros[j]; // n�o se compara valores inteiros com inteiros provenientes de ponteiros

        printf("analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i+1, num2[0], num2[1], num2[2], num2[3], num2[4], num2[5]);
        fprintf(f, "analisando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i+1, num2[0], num2[1], num2[2], num2[3], num2[4], num2[5]);
        contNum = 0;
        for(j = 0; j < 6; j++){
            for(k = 0;k < 6;k++){
                if(num2[j]==num[k]){
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
        if(contNum > 0) {
            printf(" Cont -> %d \n", contNum);
            fprintf(f, " Cont -> %d \n", contNum);
        }
        else {
                printf("\n");
                fprintf(f,"\n");
        }


    }
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    printf("\n 6:%d - 5:%d - 4:%d - 3:%d - 2:%d - 1:%d \n", senas, quinas, quadras, ternos, duque, unico);
    fprintf(f, "\n 6:%d - 5:%d - 4:%d - 3:%d - 2:%d - 1:%d \n", senas, quinas, quadras, ternos, duque, unico);
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    free(numeros);
    numeros = NULL;
    fclose(f);
    return 0;
}
