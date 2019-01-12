#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include_jogos/jogos.h"

int jogo[6];
void ordenaJogo(){
    int i, j, aux;
    for( i=0; i<5; i++ ){
        for( j=i+1; j<6; j++ ){
            if( jogo[i] > jogo[j] ){
                aux = jogo[i];
                jogo[i] = jogo[j];
                jogo[j] = aux;
            }
        }
    }
}
int contem(int dez){
    int i, result = 0;
    for(i=0;i<6;i++){
        if (jogo[i] == dez){
            result = 1;
            break;
        }
    }
    return result;
}
int main(int argv, char *argc[])
{
    int i, dez, x, a;
    srand(time(NULL));
    // ------------- Geracao de dezenas 3 pares e 3 impares ---------------
    printf("\n3 Pares e 3 Impares\n");
    for(x=0;x<1000;x++){
        i = 0;
        while(i<6){
           dez = (rand() % 60)+1;
           if ((dez%2==0) && (i<3)){
                if(!contem(dez)){
                    jogo[i] = dez;
                    i++;
                }
           }
           if ((dez%2!=0) && (i>=3)){
                if(!contem(dez)){
                    jogo[i] = dez;
                    i++;
                }
           }
        }
        ordenaJogo();
        for (i=0; i < 6; i++){
               printf("%02d ", jogo[i]);
        }
        putchar('\n');
    }
    // ----------------------------------------------------------------------
    return 0;
}
