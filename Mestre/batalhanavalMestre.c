//
// Created by Guilherme on 15/07/2025.
//
#include <stdio.h>

// Tamanho do campo
#define TamanhoYCampoNaval 10
#define TamanhoXCampoNaval 10

// Tamanho dos barcos
#define TamanhoBarco 3

// Numero representador da água
#define RepresentadorAgua 0

// Navio Horizontal 1
#define NavioHorizontal1_Y 0 // 0 A 9
#define NavioHorizontal1_X 0 // 0 A 7

// Navio Vertical 1
#define NavioVertical1_Y 4 // 0 A 7
#define NavioVertical1_X 9 // 0 A 9

// Navio Diagonal 1
#define NavioDiagonal1_Y 4 // SE OPCAO 0 - 0 A 7 // SE OPCAO 1 - 0 A 7
#define NavioDiagonal1_X 4 // SE OPCAO 0 - 0 A 7 // SE OPCAO 1 - 2 A 9
#define OpcaoNavioDiagonal1 0

// Navio Diagonal 2
#define NavioDiagonal2_Y 3
#define NavioDiagonal2_X 2
#define OpcaoNavioDiagonal2 1

// Habilidade Triangular
#define Triangulo_Y 7 // 0 A 7
#define Triangulo_X 7 // 2 A 7

// Habilidade Cruz
#define Cruz_Y 0 // 0 A 5
#define Cruz_X 7 // 2 A 7

// Habilidade Octaedro
#define Octaedro_Y 5 // 0 A 5
#define Octaedro_X 2 // 2 A 7

int campoNaval[TamanhoYCampoNaval][TamanhoXCampoNaval];

int matrizCone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int matrizCruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int matrizOctaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int HorizontalCampoNaval(int HposicaoY, int HposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Horizontal.
    for (int y = 0; y < TamanhoYCampoNaval; y++) {

        for (int x = 0; x < TamanhoXCampoNaval; x++) {

            if ( y == HposicaoY && x == HposicaoX ) {

                int PreindexY = HposicaoY;
                int PreindexX = HposicaoX;
                int VerificadorColisao = 0;

                // Verificação Previa sem atribuição das posições do navio horizontal.
                for (int j = 0; j < TamanhoBarco; j++, PreindexX++) {
                    if (campoNaval[PreindexY][PreindexX] != 0) {
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
                    for (int j = 0; j < TamanhoBarco; j++, indexX++) {
                        campoNaval[indexY][indexX] = 3;
                    };
                };

                breakLoop++;

            };

            if (breakLoop != 0) break;
            /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

        };

        if (breakLoop != 0) break;
        /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

    };

    return returnValue;

};

int VerticalCampoNaval(int VposicaoY, int VposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Vertical
    for (int y = 0; y < TamanhoYCampoNaval; y++) {

        for (int x = 0; x < TamanhoXCampoNaval; x++) {

            if ( y == VposicaoY && x == VposicaoX ) {

                int PreindexY = VposicaoY;
                int PreindexX = VposicaoX;
                int VerificadorColisao = 0;

                // Verificação Previa sem atribuição das posições do navio vertical.
                for (int j = 0; j < TamanhoBarco; j++, PreindexY++) {
                    if (campoNaval[PreindexY][PreindexX] != 0) {
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
                    for (int j = 0; j< TamanhoBarco; j++, indexY++) {
                        campoNaval[indexY][indexX] = 3;
                    };
                };

                breakLoop++;

            };

            if (breakLoop != 0) break;
            /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

        };

        if (breakLoop != 0) break;
        /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

    };

    return returnValue;

};

int DiagonalCampoNaval(int Opcao, int DposicaoY, int DposicaoX) {

    int breakLoop = 0;
    int returnValue = 0;

    // Navio Vertical
    for (int y = 0; y < TamanhoYCampoNaval; y++) {

        for (int x = 0; x < TamanhoXCampoNaval; x++) {

            if ( y == DposicaoY && x == DposicaoX ) {

                int PreindexY = DposicaoY;
                int PreindexX = DposicaoX;
                int VerificadorColisao = 0;

                if (Opcao == 0) {
                    // Verificação Previa sem atribuição das posições do navio diagonal para a direita '↘'.
                    for (int j = 0; j < TamanhoBarco; j++, PreindexY++, PreindexX++) {
                        if (campoNaval[PreindexY][PreindexX] != 0) {
                            VerificadorColisao++; // Atribui +1 a variavel que vai ser usada para verificar colisao do navio
                            returnValue++; // Atribui +1 a variavel que vai ser passada no retorno
                            break;
                        };
                    };
                } else if (Opcao == 1) {
                    // Verificação Previa sem atribuição das posições do navio diagonal para a esquerda '↙'.
                    for (int j = 0; j < TamanhoBarco; j++, PreindexY++, PreindexX--) {
                        if (campoNaval[PreindexY][PreindexX] != 0) {
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
                        for (int j = 0; j< TamanhoBarco; j++, indexY++, indexX++) {
                            campoNaval[indexY][indexX] = 3;
                        };
                    } else if (Opcao == 1) {
                        // Atribuição das posições do navio vertical para a esquerda '↙'.
                        for (int j = 0; j< TamanhoBarco; j++, indexY++, indexX--) {
                            campoNaval[indexY][indexX] = 3;
                        };
                    };

                };

                breakLoop++;

            };

            if (breakLoop != 0) break;
            /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

        };

        if (breakLoop != 0) break;
        /* Para a execução do loop interno e externo quando as posições do navio já forem definidas */

    };

    return returnValue;

};

int HabilidadeCone(int ConeposicaoY, int ConeposicaoX) {

    // Verificador previo de colisão da habilidade cone
    for ( int y = 0; y < 5; y++) {
        for ( int x = 0; x < 5; x++ ) {
            if ( matrizCone[y][x] == 1 ) {

                int i = ConeposicaoY + y;
                int j = ConeposicaoX + x - 2;

                if ( campoNaval[i][j] != 0 ) {
                    printf("===========================================================================\n");
                    printf("HOUVE COLISAO DO TRIANGULO, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("===========================================================================\n");
                    return 1;
                };

            };
        };
    };

    // Atribuidor das posições da habilidade cone
    for ( int y = 0; y < 5; y++ ) {
        for ( int x = 0; x < 5; x++ ) {
            if ( matrizCone[y][x] == 1 ) {

                int i = ConeposicaoY + y;
                int j = ConeposicaoX + x - 2;

                campoNaval[i][j] = 5;

            };
        };
    };

    return 0;

};

int HabilidadeCruz(int CposicaoY, int CposicaoX) {

    // Verificador previo de colisão da habilidade cruz
    for ( int y = 0; y < 5; y++) {
        for ( int x = 0; x < 5; x++ ) {
            if ( matrizCruz[y][x] == 1 ) {

                int i = CposicaoY + y;
                int j = CposicaoX + x - 2;
                if (i < 0) i = 0;
                if (j < 0) j = 0;
                if (campoNaval[i][j] != 0) {
                    printf("============================================================================\n");
                    printf("HOUVE COLISAO DA CRUZ, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("============================================================================\n");
                    return 1;
                };

            };
        };
    };

    // Atribuidor das posições da habilidade cruz
    for ( int y = 0; y < 5; y++) {
        for ( int x = 0; x < 5; x++ ) {
            if ( matrizCruz[y][x] == 1 ) {

                int i = CposicaoY + y;
                int j = CposicaoX + x - 2;
                if (i < 0) i = 0;
                if (j < 0) j = 0;
                campoNaval[i][j] = 5;

            };
        };
    };

    return 0;

};

int HabilidadeOctaedro(int OposicaoY, int OposicaoX) {

    // Verificador previo de colisão da habilidade octaedro
    for ( int y = 0; y < 5; y++ ) {
        for ( int x = 0; x < 5; x++ ) {
            if ( matrizOctaedro[y][x] == 1 ) {

                int i = OposicaoY + y;
                int j = OposicaoX + x - 2;
                if (i < 0) i = 0;
                if (j < 0) j = 0;
                if (campoNaval[i][j] != 0) {
                    printf("============================================================================\n");
                    printf("HOUVE COLISAO DO OCTAEDRO, POR FAVOR VERIFIQUE AS POSICOES NOVAMENTE.\n");
                    printf("============================================================================\n");
                    return 1;
                };

            };
        };
    };

    // Atribuidor das posições da habilidade octaedro
    for ( int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (matrizOctaedro[y][x] == 1) {

                int i = OposicaoY + y;
                int j = OposicaoX + x - 2;
                if (i < 0) i = 0;
                if (j < 0) j = 0;
                campoNaval[i][j] = 5;

            };
        };
    };

    return 0;

};

int main(){

    for (int y = 0; y < TamanhoYCampoNaval; y++) {
        for (int x = 0; x < TamanhoXCampoNaval; x++) {
            campoNaval[y][x] = RepresentadorAgua;
        };
    };

    // Verifica se as posições dos navios excedem os limites do mapa.
    if ( (NavioHorizontal1_Y > 9 || NavioHorizontal1_Y < 0) || (NavioHorizontal1_X > 7 || NavioHorizontal1_X < 0) ) {
        printf("==================================================\n");
        printf("PRIMEIRO NAVIO HORIZONTAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    };

    if ( (NavioVertical1_Y > 7 || NavioVertical1_Y) < 0 || (NavioVertical1_X > 9 || NavioVertical1_X < 0) ) {
        printf("==================================================\n");
        printf("SEGUNDO NAVIO HORIZONTAL FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    };

    if (OpcaoNavioDiagonal1 == 0) {
        if ( (NavioDiagonal1_Y > 7 || NavioDiagonal1_Y < 0) || (NavioDiagonal1_X > 7 || NavioDiagonal1_X < 0 ) ) {
            printf("==================================================\n");
            printf("PRIMEIRO NAVIO DIAGONAL NA DIREÇÃO DIREITA FORA DOS LIMITES DO MAPA.\n");
            printf("==================================================\n");
            return 0;
        };
    };

    if (OpcaoNavioDiagonal1 == 1) {
        if ( (NavioDiagonal2_Y > 7 || NavioDiagonal2_Y < 0) || (NavioDiagonal2_X < 2 || NavioDiagonal2_X > 9) ) {
            printf("==================================================\n");
            printf("PRIMEIRO NAVIO DIAGONAL NA DIREÇÃO ESQUERDA FORA DOS LIMITES DO MAPA.\n");
            printf("==================================================\n");
            return 0;
        };
    };

    if (OpcaoNavioDiagonal2 == 0) {
        if ( (NavioDiagonal1_Y > 7 || NavioDiagonal1_Y < 0) || (NavioDiagonal1_X > 7 || NavioDiagonal1_X < 0 ) ) {
            printf("==================================================\n");
            printf("SEGUNDO NAVIO DIAGONAL NA DIREÇÃO DIREITA FORA DOS LIMITES DO MAPA.\n");
            printf("==================================================\n");
            return 0;
        };
    };

    if (OpcaoNavioDiagonal2 == 1) {
        if ( (NavioDiagonal2_Y > 7 || NavioDiagonal2_Y < 0) || (NavioDiagonal2_X < 2 || NavioDiagonal2_X > 9) ) {
            printf("==================================================\n");
            printf("SEGUNDO NAVIO DIAGONAL NA DIREÇÃO ESQUERDA FORA DOS LIMITES DO MAPA.\n");
            printf("==================================================\n");
            return 0;
        };
    };

    if ( (Triangulo_Y > 7 || Triangulo_Y < 0) || (Triangulo_X < 2  || Triangulo_X > 7) ) {
        printf("==================================================\n");
        printf("HABILIDADE TRIANGULO FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    };

    if ( (Cruz_Y > 5 || Cruz_Y < 0) || (Cruz_X < 2  || Cruz_X > 7) ) {
        printf("==================================================\n");
        printf("HABILIDADE CRUZ FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    };

    if (Octaedro_Y > 5 || Octaedro_Y < 0 || Octaedro_X < 2 || Octaedro_X > 7) {
        printf("==================================================\n");
        printf("HABILIDADE OCTAEDRO FORA DOS LIMITES DO MAPA.\n");
        printf("==================================================\n");
        return 0;
    };

    /*
     * Funções para definir as posições dos navios horizontais e verticais.
     *
     * Obs: Cada função porta o seu próprio verificador de colisão, antes de atribuir '3'
     * que simboliza o navio, O verificador faz o mapeamento das posições que o navio vai ocupar
     * e verifica se já não existe um '3' antes dele, e se for encontrado '== Colisão',
     * se não for encontrado, as posições estão livres, e ele vai atribuir os '3' tranquilamente.
     */

    int resultadoOctaedro = HabilidadeOctaedro(Octaedro_Y, Octaedro_X);
    int resultadoTriangulo = HabilidadeCone(Triangulo_Y, Triangulo_X);
    int resultadoCruz = HabilidadeCruz(Cruz_Y, Cruz_X);
    int resultadoNavioHorizontal1 = HorizontalCampoNaval(NavioHorizontal1_Y, NavioHorizontal1_X);
    int resultadoNavioVertical1 = VerticalCampoNaval(NavioVertical1_Y, NavioVertical1_X);
    int resultadoNavioDiagonal1 = DiagonalCampoNaval(OpcaoNavioDiagonal1,NavioDiagonal1_Y, NavioDiagonal1_X);
    int resultadoNavioDiagonal2 = DiagonalCampoNaval(OpcaoNavioDiagonal2,NavioDiagonal2_Y, NavioDiagonal2_X);

    /*
     * Se os retornos das funções não forem todos '0', indica que houve colisão
     * na posição de um navio, e bloqueia a impressão da matriz.
     */

    if ( resultadoNavioHorizontal1 == 0 && resultadoNavioVertical1 == 0 && resultadoNavioDiagonal1 == 0 && resultadoNavioDiagonal2 == 0) {
        if (resultadoTriangulo == 0 && resultadoCruz == 0 && resultadoOctaedro == 0) {

            printf("========== CAMPO DA BATALHA NAVAL ==========\n");
            printf("- | A | B | C | D | E | F | G | H | I | J |\n");

            // Exibe o Campo Naval
            int num = 0;
            for (int y = 0; y < TamanhoYCampoNaval; y++) {
                printf("%d |", num);
                for (int x = 0; x < TamanhoXCampoNaval; x++) {
                    printf(" %d |", campoNaval[y][x]);
                };
                printf(" \n");
                num++;
            };

        };

    };

    return 0;

};