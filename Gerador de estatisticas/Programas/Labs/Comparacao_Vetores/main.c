#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, cont;
    int senas=0, quinas=0, quadras=0;
    int vetor1[3][6] = {{1,2,4,8,12,15},
                        {1,2,3,8,12,15},
                        {1,2,3,9,12,15}};
    int vetor2[6] = {1,2,4,8,12,15};
    for(k=0;k<3;k++){
        cont = 0;
        for (i=0;i<6;i++){
            for(j=0;j<6;j++){
                if(vetor1[k][i] == vetor2[j]){
                    cont++;
                    break;
                }
            }
        }
        printf("processando sequencia: %d : %d - %d - %d - %d - %d - %d ->> cont: %d\n", k, vetor1[k][0], vetor1[k][1], vetor1[k][2], vetor1[k][3], vetor1[k][4], vetor1[k][5], cont);
        if (cont == 4) quadras++;
        if (cont == 5) quinas++;
        if (cont == 6) senas++;
    }
    printf("Quantidade: %d  ->  Senas: %d, Quinas: %d, Quadras: %d\n", cont, senas, quinas, quadras);
}
