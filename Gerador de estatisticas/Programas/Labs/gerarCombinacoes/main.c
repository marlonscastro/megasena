#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, x, _x = 0, y, MAX = 18, cont = 0;
    FILE *f;
    int mais[15] =   { 5,53,51, 4,23,       54,42,10,17,41,       33,24,13,28,30}, maisTemp[15];

    int comuns[30] = {50,32, 2,49,16,       52,29,27,34,37,        43,44,47,56, 1,
                      36,31, 6,18, 8,       12,59,58,38,45,        7, 3,35,11,60}, comunsTemp[30];

    int menos[15] =  {46,20,40,19,57,       48,14,15,25,39,        9,55,21,22,26}, menosTemp[15];

    int dezenasFixas[18] = {16,17,19,28,45,58,
                            21,31,35,53,54,57,
                             2, 3, 5,10,15,34};

    int dezenas[18];    // Array de Dezenas temporárias
    int gerados[5000][3];
    int ignorados[5000][15];
    int _maisCont=0, _comunsCont=0, _menosCont=0;
    int jogo7Dezenas[7] = {0,0,0,0,0,0,0};
    int dezenaTemp;
    srand(time(NULL));
    // Eliminar Repetidas nas dezenas fixas
    for(i=0;i<18;i++){
        for(j=i+1;j<17;j++){
            if(dezenasFixas[i] == dezenasFixas[j])
                dezenasFixas[j] = 0;
        }
    }
    f = fopen("saida.txt", "w");
    // Gera todas as combinacoes e divide-as entre GER e IGN
    for(i=0;i<MAX;i++){
        for(j=i;j<MAX;j++){
            for(k=j;k<MAX;k++){
                for(x=0;x<18;x++)
                    dezenas[x] = dezenasFixas[x];
                if ((dezenas[i]!=dezenas[j]) && (dezenas[j]!=dezenas[k])){
                    //printf("%02d %02d %02d\n", dezenas[i], dezenas[j], dezenas[k]);
                    //fprintf(f, "%02d %02d %02d\n", dezenas[i], dezenas[j], dezenas[k]);
                    gerados[cont][0] = dezenas[i];
                    gerados[cont][1] = dezenas[j];
                    gerados[cont][2] = dezenas[k];
                    dezenas[i] = 0;
                    dezenas[j] = 0;
                    dezenas[k] = 0;
                    x = 0;
                    _x = 0;
                    while(x<18){
                        if(dezenas[x]!=0){
                            ignorados[cont][_x] = dezenas[x];
                            _x++;
                        }
                        x++;
                    }
                    cont++;
                }
            }
        }
    }
    printf("----------------------------------------\n");
    fprintf(f, "----------------------------------------\n");
    printf("Total: %d\n\n", cont);
    fprintf(f, "Total: %d\n\n", cont);
    int contZeros=0, contJogos=0;
    for(i=0;i<cont;i++){
        for(k=0;k<3;k++){
            if(gerados[i][k] == 0){
                contZeros++;
                break;
            }
        }
        if(contZeros==0){
            contJogos++;
            printf("%03d - GER: ", contJogos);
            fprintf(f, "%03d - GER: ", contJogos);
            for(j=0;j<3;j++){
                printf("%02d ", gerados[i][j]);
                fprintf(f, "%02d ", gerados[i][j]);
            }
            printf("IGN: ");
            fprintf(f, "IGN: ");
            for(j=0;j<15;j++){
                printf("%02d ", ignorados[i][j]);
                fprintf(f,"%02d ", ignorados[i][j]);
            }
            printf("\n");
            fprintf(f,"\n");
        }
        contZeros = 0;
    }
    printf("\n--------------------- QUANT JOGOS: %d  -----------------------\n", contJogos);

    // COPIAR TABELA MCM PARA OS VETORES TEMPORARIOS
    for(i=0;i<30;i++) {
        if(i<15){
            maisTemp[i] = mais[i];
            menosTemp[i] = menos[i];
        }
        comunsTemp[i] = comuns[i];
    }
    // Eliminar as dezenas IGNORADAS das tabelas temporarias (Testado)
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            if(j<15){
                if(ignorados[0][i] == maisTemp[j])  maisTemp[j] = 0;
                if(ignorados[0][i] == menosTemp[j]) menosTemp[j] = 0;
            }
            if(ignorados[0][i] == comunsTemp[j]) comunsTemp[j] = 0;
        }
    }
    // Eliminar as dezenas GERADAS das tabelas temporarias (Testado)
    for(i=0;i<3;i++){
        for(j=0;j<30;j++){
            if(j<15){
                if(gerados[0][i] == maisTemp[j])  maisTemp[j] = 0;
                if(gerados[0][i] == menosTemp[j]) menosTemp[j] = 0;
            }
            if(gerados[0][i] == comunsTemp[j]) comunsTemp[j] = 0;
        }
    }
    // Verificar a quem as 3 dezenas Geradas pertence, quais faixas de valores (mais, comuns, menos)
    // PARA a organizacao mais comum 2-3-2
    _maisCont = 2;
    _comunsCont = 3;
    _menosCont = 2;
    int _dezenasCont = 3; // o Vetor jogo ja contem 3 dezenas

    for(i=0;i<3;i++)
        jogo7Dezenas[i] = gerados[0][i];   // Carregando as combinacoes de 3 para o vetor jogo

    for(i=0;i<3;i++){  // TESTADO -- OK
        for(j=0;j<30;j++){
            if(j<15){
                if(jogo7Dezenas[i] == mais[j])  _maisCont--;
                if(jogo7Dezenas[i] == menos[j]) _menosCont--;
            }
            if(jogo7Dezenas[i] == comuns[j]) _comunsCont--;
        }
    }

    int indiceDezena=0;

    // ------------------------ TESTADO OK -------------------------------
    while(_maisCont>0){
        indiceDezena = rand() % 15;
        dezenaTemp = maisTemp[indiceDezena];
        if(dezenaTemp!=0){
            _maisCont--;
            jogo7Dezenas[_dezenasCont] = dezenaTemp;
            maisTemp[indiceDezena] = 0;
            _dezenasCont++;
        }
    }
    while(_menosCont>0){
        indiceDezena = rand() % 15;
        dezenaTemp = menosTemp[indiceDezena];
        if(dezenaTemp!=0){
            _menosCont--;
            jogo7Dezenas[_dezenasCont] = dezenaTemp;
            menosTemp[indiceDezena] = 0;
            _dezenasCont++;
        }
    }
    while(_comunsCont>0){
        indiceDezena = rand() % 30;
        dezenaTemp = comunsTemp[indiceDezena];
        if(dezenaTemp!=0){
            _comunsCont--;
            jogo7Dezenas[_dezenasCont] = dezenaTemp;
            comunsTemp[indiceDezena] = 0;
            _dezenasCont++;
        }
    }
    // ------------------------ FIM, TESTADO OK -------------------------------

    printf("Jogo Gerado: ");
    for(i=0;i<7;i++){
        printf("%02d ", jogo7Dezenas[i]);
    }
    fclose(f);
}
