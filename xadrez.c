#include <stdio.h>

int main() {

    /* ===============================
       Movimentos das peças anteriores
       (exemplo do desafio básico)
       =============================== */

    int i;

    // Torre - movendo 3 casas para a direita
    for (i = 0; i < 3; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Bispo - movendo 2 casas para cima e direita
    for (i = 0; i < 2; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }

    printf("\n");

    // Rainha - movendo 2 casas para cima
    for (i = 0; i < 2; i++) {
        printf("Cima\n");
    }

    /* ===============================
       Movimento do Cavalo
       Duas casas para baixo
       Uma casa para a esquerda
       Usando loops aninhados
       =============================== */

    printf("\n"); // separa o movimento do Cavalo dos anteriores

    int casasBaixo = 2;
    int casasEsquerda = 1;
    int contador;

    // Loop externo (for): controla o movimento principal
    for (i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");

        // Loop interno (while): executa após completar o movimento vertical
        if (i == casasBaixo - 1) {
            contador = 0;
            while (contador < casasEsquerda) {
                printf("Esquerda\n");
                contador++;
            }
        }
    }

    return 0;
}
