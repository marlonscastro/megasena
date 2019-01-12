#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"

int vetor[6];
//char r[7][10];
int naoRepetidos(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
    const int MAX = 10;
    int retorno = 0, x, y;
    int vetor[10] = {a,b,c,d,e,f,g,h,i,j};

    for(x=0;x<MAX;x++){
        for(y=(x+1);y<MAX;y++){
            if (vetor[x] == vetor[y])
               retorno = 1;
               break;
               break;
        }
    }
    return retorno;
}

void geraSequencias(){
    int i, j, k, l, m, n, o, p, q, r, cont = 0;
    const int MAX = 60;
    printf("--------- Gerador de Sequencias ----------\n");

    for(i = 1; i <= MAX;i++)
        for(j = i;j <= MAX;j++)
            for(k = j;k <= MAX;k++)
                for(l = k;l <= MAX;l++)
                    for(m = l;m <= MAX;m++)
                        for(n = m;n <= MAX;n++)
                            for(o = n;o <= MAX;o++)
                                for(p = o;p <= MAX;p++)
                                    for(q = p;q <= MAX;q++)
                                        for(r = q;r <= MAX;r++)
                                            if (naoRepetidos(i,j,k,l,m,n,o,p,q,r) == 0){
                                                cont++;
                                                printf("%02d > %02d - %02d - %02d - %02d - %02d - %02d - %02d - %02d - %02d - %02d\n", cont, i, j, k, l, m, n, o, p, q, r);
                                            }
    printf("\n\ntotal de sequencias: %d\n\n\n", cont);
}



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
    char fileName[50], fcat[3];
    int num[6] = {0,0,0,0,0,0};
    numeros = (int *) malloc(6 * sizeof(int));
    int jogo[7] = {1,6,10,15,50,54,57};
    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "Jogo");
    for(i = 0; i < sizeof(jogo)/4; i++){
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
        //numeros = getNumerosMega(i);
        //for(j=0;j<6;j++) num[j] = numeros[j]; // não se compara valores inteiros com inteiros provenientes de ponteiros
        for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros
        contNum = 0;
        for(j = 0; j < 6; j++){
            for(k = 0; k < sizeof(jogo)/4; k++){
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
            printf("processando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i, num[0], num[1], num[2], num[3], num[4], num[5]);
            //fprintf(f, "processando jogo %04d | %02d - %02d - %02d - %02d - %02d - %02d", i, num[0], num[1], num[2], num[3], num[4], num[5]);
            printf(" -> Cont: %d\n", contNum);
            //fprintf(f," -> Cont: %d\n", contNum);
        }
    }
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    printf("\nSenas: %d, Quinas: %d, Quadras: %d, Ternos: %d, Duques: %d, Unico: %d\n", senas, quinas, quadras, ternos, duque, unico);
    fprintf(f, "\nSenas: %d, Quinas: %d, Quadras: %d, Ternos: %d, Duques: %d, Unico: %d\n", senas, quinas, quadras, ternos, duque, unico);
    printf("------------------------------------------------------------------------");
    fprintf(f, "------------------------------------------------------------------------");
    fclose(f);
    free(numeros);
    numeros = NULL;
    return 0;
}
