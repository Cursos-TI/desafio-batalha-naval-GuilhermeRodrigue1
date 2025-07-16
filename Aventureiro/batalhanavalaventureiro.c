//
// Created by Guilherme on 14/07/2025.
//
#include <stdio.h>
// Navio Horizontal 1
#define NavioHorizontal1_Y 0
#define NavioHorizontal1_X 0
// Navio Vertical 1
#define NavioVertical1_Y 6
#define NavioVertical1_X 1
// Navio Diagonal 1
#define NavioDiagonal1_Y 6
#define NavioDiagonal1_X 6
#define OpcaoNavioDiagonal1 0
// Navio Diagonal 2
#define NavioDiagonal2_Y 2
#define NavioDiagonal2_X 3
#define OpcaoNavioDiagonal2 1

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
                    printf("============================================================================\n");
                    printf("HOUVE COLISAO DO NAVIO HORIZONTAL, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("============================================================================\n");
                } else {
                    int indexY = HposicaoY;
                    int indexX = HposicaoX;
                    // Atribuição das posições do navio Horizontal.
                    for (int j = 0; j < 3; j++, indexX++) {
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
                    printf("===========================================================================\n");
                    printf("HOUVE COLISAO DO NAVIO VERTICAL, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("===========================================================================\n");
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

int DiagonalCampoNaval(int Opcao, int DposicaoY, int DposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Vertical
    for (int y = 0; y < 10; y++) {

        for (int x = 0; x < 10; x++) {

            if ( y == DposicaoY && x == DposicaoX ) {

                int PreindexY = DposicaoY;
                int PreindexX = DposicaoX;
                int VerificadorColisao = 0;

                if (Opcao == 0) {
                    // Verificação Previa sem atribuição das posições do navio diagonal para a direita '↘'.
                    for (int j = 0; j < 3; j++, PreindexY++, PreindexX++) {
                        if (campoNaval[PreindexY][PreindexX] == 3) {
                            VerificadorColisao++; // Atribui +1 a variavel que vai ser usada para verificar colisao do navio
                            returnValue++; // Atribui +1 a variavel que vai ser passada no retorno
                            break;
                        };
                    };
                } else if (Opcao == 1) {
                    // Verificação Previa sem atribuição das posições do navio diagonal para a esquerda '↙'.
                    for (int j = 0; j < 3; j++, PreindexY++, PreindexX--) {
                        if (campoNaval[PreindexY][PreindexX] == 3) {
                            VerificadorColisao++; // Atribui +1 a variavel que vai ser usada para verificar colisao do navio
                            returnValue++; // Atribui +1 a variavel que vai ser passada no retorno
                            break;
                        };
                    };
                }

                if (VerificadorColisao != 0) {
                    printf("===========================================================================\n");
                    printf("HOUVE COLISAO DO NAVIO DIAGONAL, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("===========================================================================\n");
                } else {
                    int indexY = DposicaoY;
                    int indexX = DposicaoX;

                    if (Opcao == 0) {
                        // Atribuição das posições do navio vertical para a direita '↘'.
                        for (int j = 0; j< 3; j++, indexY++, indexX++) {
                            campoNaval[indexY][indexX] = 3;
                        };
                    } else if (Opcao == 1) {
                        // Atribuição das posições do navio vertical para a esquerda '↙'.
                        for (int j = 0; j< 3; j++, indexY++, indexX--) {
                            campoNaval[indexY][indexX] = 3;
                        };
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

    // Verifica se as posições dos navios excedem os limites do mapa.
    if ( (NavioHorizontal1_Y > 9 || NavioHorizontal1_X > 7) || (NavioHorizontal1_Y < 0 || NavioHorizontal1_X < 0) ) {
        printf("==================================================\n");
        printf("PRIMEIRO NAVIO HORIZONTAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    } else if ( (NavioVertical1_Y > 7 || NavioVertical1_X > 9) || (NavioVertical1_Y < 0 || NavioVertical1_X < 0) ) {
        printf("==================================================\n");
        printf("SEGUNDO NAVIO HORIZONTAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    } else if ( (NavioDiagonal1_Y > 7 || NavioDiagonal1_X > 7) || (NavioDiagonal1_Y < 0 || NavioDiagonal1_X < 0) ) {
        printf("==================================================\n");
        printf("PRIMEIRO NAVIO DIAGONAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    } else if ( (NavioDiagonal2_Y > 7 || NavioDiagonal2_X < 2) || (NavioDiagonal2_Y < 0 || NavioDiagonal2_X < 0) ) {
        printf("==================================================\n");
        printf("SEGUNDO NAVIO DIAGONAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    }

    /*
     * Funções para definir as posições dos navios horizontais e verticais.
     *
     * Obs: Cada função porta seu própio verificador de colisão, antes de atribuir '3'
     * que simboliza o navio, O verificador faz o mapeamento das posições que o navio vai ocupar
     * e verifica se já não existe um '3' antes dele, e se for encontrado '== Colisão',
     * se nao for encontrado, as posições estão livres, e ele vai atribuir os '3' tranquilamente.
     */
    int resultadoNavioHorizontal1 = HorizontalCampoNaval(NavioHorizontal1_Y, NavioHorizontal1_X);
    int resultadoNavioVertical1 = VerticalCampoNaval(NavioVertical1_Y, NavioVertical1_X);
    int resultadoNavioDiagonal1 = DiagonalCampoNaval(OpcaoNavioDiagonal1,NavioDiagonal1_Y, NavioDiagonal1_X);
    int resultadoNavioDiagonal2 = DiagonalCampoNaval(OpcaoNavioDiagonal2,NavioDiagonal2_Y, NavioDiagonal2_X);

    /*
     * Se os retornos das funções não forem todos '0', indica que houve colisão
     * na posição de um navio, e bloqueia a impressão da matriz.
     */
    if ( (resultadoNavioHorizontal1 == 0 && resultadoNavioVertical1 == 0) && (resultadoNavioDiagonal1 == 0 && resultadoNavioDiagonal2 == 0) ) {

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

    };

    return 0;

};