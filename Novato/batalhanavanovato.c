//
// Created by Guilherme on 12/07/2025.
//
#include <stdio.h>

int campoNaval[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int HorizontalCampoNaval(int HposicaoY, int HposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Horizontal.
    for (int y = 0; y < 10; y++) {

        for (int x = 0; x < 10; x++) {

            if ( y == HposicaoY && x == HposicaoX ) {

                int PreindexY = HposicaoY;
                int PreindexX = HposicaoX;
                int VerificadorColisao = 0;

                // Verificação Previa sem atribuição das posições do navio horizontal.
                for (int j = 0; j < 3; j++, PreindexX++) {
                    if (campoNaval[PreindexY][PreindexX] == 3) {
                        VerificadorColisao++; // Atribui +1 a variavel que vai ser usada para verificar colisao do navio
                        returnValue++; // Atribui +1 a variavel que vai ser passada no retorno
                        break;
                    };
                };

                if (VerificadorColisao != 0) {
                    printf("Colisao do navio horizontal.\n");
                } else {
                    int indexY = HposicaoY;
                    int indexX = HposicaoX;
                    // Atribuição das posições do navio Horizontal.
                    for (int j = 0; j < 3; j++, HposicaoX++) {
                        campoNaval[HposicaoY][HposicaoX] = 3;
                    };
                };

                breakLoop++;

            };

            if (breakLoop != 0) break;
            /* Para a execução do loop interno e externo quando as posições do navios ja forem definidas */

        };

        if (breakLoop != 0) break;
        /* Para a execução do loop interno e externo quando as posições do navios ja forem definidas */

    };

    return returnValue;

};

int VerticalCampoNaval(int VposicaoY, int VposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Vertical
    for (int y = 0; y < 10; y++) {

        for (int x = 0; x < 10; x++) {

            if ( y == VposicaoY && x == VposicaoX ) {

                int PreindexY = VposicaoY;
                int PreindexX = VposicaoX;
                int VerificadorColisao = 0;

                // Verificação Previa sem atribuição das posições do navio vertical.
                for (int j = 0; j < 3; j++, PreindexY++) {
                    if (campoNaval[PreindexY][PreindexX] == 3) {
                        VerificadorColisao++; // Atribui +1 a variavel que vai ser usada para verificar colisao do navio
                        returnValue++; // Atribui +1 a variavel que vai ser passada no retorno
                        break;
                    };
                };

                if (VerificadorColisao != 0) {
                    printf("Colisao do navio vertical.\n");
                } else {
                    int indexY = VposicaoY;
                    int indexX = VposicaoX;
                    // Atribuição das posições do navio vertical.
                    for (int j = 0; j< 3; j++, indexY++) {
                        campoNaval[indexY][indexX] = 3;
                    };
                };

                breakLoop++;

            };

            if (breakLoop != 0) break;
            /* Para a execução do loop interno e externo quando as posições do navios ja forem definidas */

        };

        if (breakLoop != 0) break;
        /* Para a execução do loop interno e externo quando as posições do navios ja forem definidas */

    };

    return returnValue;

};

int main(){

    /*
     * HposicaoY = Define o eixo cima e baixo do 'Navio Horizontal'
     * HposicaoX = Define o eixo Esuqerda e Direita do 'Navio Horizontal'
     */
    int HposicaoY = 2, HposicaoX = 1;

    /*
     * VposicaoY = Define o eixo cima e baixo do 'Navio Vertical'
     * VposicaoX = Define o eixo Esuqerda e Direita do 'Navio Vertical'
     */
    int VposicaoY = 6, VposicaoX = 8;

    if ( (HposicaoY > 9 || HposicaoX > 7) || (HposicaoY < 0 || HposicaoX < 0) ) {
        printf("==========================================\n");
        printf("NAVIO HORIZONTAL FORA DOS LIMITES DO MAPA.\n");
        printf("==========================================\n");
        return 0;
    } else if ((VposicaoY > 7 || VposicaoX > 9) || (VposicaoY < 0 || VposicaoX < 0)) {
        printf("==========================================\n");
        printf("NAVIO VERTICAL FORA DOS LIMITES DO MAPA.\n");
        printf("==========================================\n");
        return 0;
    };

    int resultadoNavioHorizontal = HorizontalCampoNaval(HposicaoY, HposicaoX);
    int resultadoNavioVertical = VerticalCampoNaval(VposicaoY, VposicaoX);

    if (resultadoNavioHorizontal == 0 && resultadoNavioVertical == 0) {

        printf("======== CAMPO DA BATALHA NAVAL ========\n");
        printf("A | B | C | D | E | F | G | H | I | J |\n");
        printf("---------------------------------------\n");

        // Exibe o Campo Naval
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                printf("%d | ", campoNaval[y][x]);
            };
            printf("\n");
        };

    }

    return 0;
};