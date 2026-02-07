#include <stdio.h>

int main() {

    /* ================================
       MOVIMENTO DA TORRE
       Estrutura usada: FOR
       Torre andando 5 casas para a direita
       ================================ */
    
    int casasTorre = 5;
    int i;

    printf("Movimento da TORRE:\n");

    for (i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");


    /* ================================
       MOVIMENTO DO BISPO
       Estrutura usada: WHILE
       Bispo andando 5 casas na diagonal
       (Cima + Direita)
       ================================ */

    int casasBispo = 5;
    int contadorBispo = 1;

    printf("Movimento do BISPO:\n");

    while (contadorBispo <= casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");


    /* ================================
       MOVIMENTO DA RAINHA
       Estrutura usada: DO-WHILE
       Rainha andando 8 casas para a esquerda
       ================================ */

    int casasRainha = 8;
    int contadorRainha = 1;

    printf("Movimento da RAINHA:\n");

    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    return 0;
}
