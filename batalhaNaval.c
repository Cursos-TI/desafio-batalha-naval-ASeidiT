#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

   
    int tabuleiro[10][10]; // Tabuleiro (Matriz 10 x 10)
    int i, j; // Variáveis para os loops

    // Inicializa todo o tabuleiro com água
    for (i = 0; i < 10; i++) { // Loop pelas linhas
    for (j = 0; j < 10; j++) { // Loop pelas colunas
        tabuleiro[i][j] = 0; // Atribui 0 a cada célula
    }
    }


// Navio horizontal - Tamanho 3
    int linhaNavioH = 1; // Linha onde o navio horizontal vai ficar (índice 2 = terceira linha)
    int colunaInicioNavioH = 1; // Coluna onde o navio começa (índice 3 = quarta coluna, 'D')

    printf("Colocando navio horizontal...\n");
    for (int k = 0; k < 3; k++) { // Repete para cada parte do navio
        int colunaAtual = colunaInicioNavioH + k; // Calcula a coluna da parte atual

        // Verifica se a coluna atual está dentro dos limites do tabuleiro
        if (colunaAtual < 10) {
             tabuleiro[linhaNavioH][colunaAtual] = 3; // Coloca o valor 3 na posição
        }
    }

// Navio vertical - Tamanho 3
    int linhaInicioNavioV = 4; // Linha onde o navio vertical começa (índice 5 = sexta linha)
    int colunaNavioV = 7; // Coluna onde o navio vertical vai ficar (índice 7 = oitava coluna, 'H')

    printf("Colocando navio vertical...\n");
    for (int k = 0; k < 3; k++) { // Repete para cada parte do navio
        int linhaAtual = linhaInicioNavioV + k; // Calcula a linha da parte atual

        // Verifica se a linha atual está dentro dos limites do tabuleiro
        if (linhaAtual < 10) {
            tabuleiro[linhaAtual][colunaNavioV] = 3; // Coloca o valor 3 na posição
        }
    }

// Posiciona navio diagonal 1 (esquerda para direita)
    for (i = 1; i <= 3; i++) {
        for (j = 7; j <= 9; j++) {
            if (i - 1 == j - 7) {
                tabuleiro[i][j] = 3;
            }
        }
    }

// Posiciona navio diagonal 2 (direita para esquerda) - seu original
    for ( j = 2; j <  2 + 1; j++){
        for( j = 1; j < 1 + 1; j++){
            for( j = 0; j < 0 + 1; j++){
                tabuleiro[9][j] = 3;
            }
            tabuleiro[8][j] = 3;
        }
        tabuleiro[7][j] = 3;
    }

// Poder em forma de cone com topo em linha 7, coluna 5
    int centro = 5;
    int linhaTopo = 7;
    for (i = 0; i < 3; i++) { // 3 linhas: 7, 8, 9
        int linha = linhaTopo + i;
        if (linha >= 10) break;
        for (j = centro - i; j <= centro + i; j++) {
            if (j >= 0 && j < 10) {
                if (tabuleiro[linha][j] == 0) {
                    tabuleiro[linha][j] = 4; // substitui apenas se for água
                }
            }
        }
    }

// 4.Exibindo o tabuleiro

    printf("\n--- Tabuleiro Final ---\n");
    printf("    "); // Espaço para alinhar com os números das linhas
    for(j = 0; j < 10; j++) printf(" %c ", 'A' + j); // Imprime letras A-J
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d |", i + 1); // Imprime número da linha 1-10
        for (j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]); // Imprime o valor da célula (0 ou 3)
        }
        printf("|\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
