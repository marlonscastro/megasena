#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, total = 0, vetor[] = {1,2,6,5,4};
    /*printf("%d \n", sizeof(vetor)/4);
    char fileName[50], num[3];
    //fileName = (char *) malloc(sizeof(vetor)/4*sizeof(char)+4);
    for(i = 0; i < sizeof(vetor)/4;i++){
        sprintf(num, "%d-", vetor[i]);
        strcat(fileName, num);
    }
    strcat(fileName, ".txt");

    printf("\n\n %s", fileName);
    return 0;*/

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            for(k=0;k<7;k++){
                if((i+j+k) == 6){
                    printf("   %d %d %d   \n", i, j, k);
                    total++;
                }
            }
        }
    }
    printf("total ::: %d \n\n\n", total);
    total = 0;
    for(i=1;i<=60;i++){
        for(j=i;j<=60;j++){
            if((i!=j) && (i%10==j%10)){
                printf("%d - %d \n", i, j);
                total++;
            }
        }
    }
    printf("%d ", total);

}
