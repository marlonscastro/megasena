#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include_jogos/jogos.h"

int vetor[6];
int numeros[60], quantNum[60];
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

void ordenaVetor(){
    int i, j, aux, aux2;
    for( i=0; i<60; i++ ){
        for( j=i+1; j<61; j++ ){
            if( quantNum[i] < quantNum[j] ){
                aux = quantNum[i];
                aux2 = numeros[i];
                quantNum[i] = quantNum[j];
                numeros[i] = numeros[j];
                quantNum[j] = aux;
                numeros[j] = aux2;

            }
        }
    }
}
int main(int argv, char *argc[])
{
    int contNum;
    int unico=0;
    int i, j, x;
    char fileName[50];
    int num[6] = {0,0,0,0,0,0};

    for(i=0;i<60;i++)
        numeros[i] = i+1;
    memset(quantNum, 0, 60);

    FILE *f;

    memset(fileName, 0, 50);
    strcat(fileName, "OcorrenciasDezenas.txt");
    f = fopen(fileName, "w");
    if(!f){
        printf("erro ao criar o arquivo: %s\n", fileName);
        exit(0);
    }
    printf("Arquivo \"%s\" Criado com sucesso... \n\n", fileName);

    int contUniversal=0;
    int vetorPeso[11388];
    for(x = 1; x <= 60; x++){
        unico = 0;
        for(i = 0; i < sizeof(jogosMega)/24; i++){
            for(j=0;j<6;j++) num[j] = jogosMega[i][j]; // não se compara valores inteiros com inteiros provenientes de ponteiros
            contNum = 0;
            for(j = 0; j < 6; j++){
                if(num[j] == x){
                    contNum++;
                    break;
                }
            }
            if(contNum == 1) {
                unico++;
            }
            //vetorPeso[contUniversal++]=num[j];
        }
        quantNum[x-1] = unico;
    }
    ordenaVetor();
    for(i=0;i<15;i++){
        printf("------------------------------------------------------------------------");
        //fprintf(f, "------------------------------------------------------------------------");
        printf("\n dezena %02d: %d\n", numeros[i], quantNum[i]);
        fprintf(f, "%02d  ", numeros[i]);
    }
    fprintf(f, "\n");
    //fprintf(f, "%02d(%d) ", numeros[i], quantNum[i]);
    for(i=15;i<45;i++){
        printf("------------------------------------------------------------------------");
        //fprintf(f, "------------------------------------------------------------------------");
        printf("\n dezena %02d: %d\n", numeros[i], quantNum[i]);
        fprintf(f, "%02d  ", numeros[i]);

    }
    fprintf(f, "\n");
    for(i=45;i<60;i++){
        printf("------------------------------------------------------------------------");
        //fprintf(f, "------------------------------------------------------------------------");
        printf("\n dezena %02d: %d\n", numeros[i], quantNum[i]);
        fprintf(f, "%02d  ", numeros[i]);
    }
    int total =0 ;
    for(i=0;i<sizeof(quantNum)/4;i++)
        total +=quantNum[i];
    printf("\n\n Total : %d\n\n", contUniversal);


    for(i=0;i<200;i++){
        printf("%02d - ", vetorPeso[i]);
    }
    fclose(f);
    return 0;
}
