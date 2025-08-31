#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

#include <stdio.h>
#include <stdbool.h>

// Funções recursivas para movimentar as peças,
// conforme solicitado no Nível Mestre.

// Move o Bispo recursivamente.
void moverBispo(int passos) {
    // Condição de parada para evitar loop infinito.
    if (passos <= 0) {
        return;
    }

    // Um passo do bispo na diagonal é cima + direita.
    printf("  Passo: Cima e Direita\n");
    
    // Chama a função novamente com um passo a menos.
    moverBispo(passos - 1);
}

// Move a Torre recursivamente.
void moverTorre(int passos) {
    // Base da recursão.
    if (passos <= 0) {
        return;
    }
    
    printf("  Passo: Direita\n");
    moverTorre(passos - 1);
}

// Move a Rainha recursivamente.
void moverRainha(int passos) {
    if (passos <= 0) {
        return;
    }
    
    printf("  Passo: Esquerda\n");
    moverRainha(passos - 1);
}


int main() {
    // Constantes para os movimentos das peças.
    const int MOV_BISPO = 5;
    const int MOV_TORRE = 5;
    const int MOV_RAINHA = 8;

    printf("Iniciando simulação de movimentos - Desafio MateCheck\n\n");

    // --- Movimentação das Peças com Recursão ---
    
    printf("Movimento do Bispo (%d casas):\n", MOV_BISPO);
    moverBispo(MOV_BISPO);
    printf("\n");

    printf("Movimento da Torre (%d casas):\n", MOV_TORRE);
    moverTorre(MOV_TORRE);
    printf("\n");

    printf("Movimento da Rainha (%d casas):\n", MOV_RAINHA);
    moverRainha(MOV_RAINHA);
    printf("\n");

    // --- Movimentação do Cavalo com Loop Avançado ---
    // Movimento em L: 2 casas para cima, 1 para direita.
    
    printf("Movimento do Cavalo (L para cima e direita):\n");

    const int PASSOS_CAVALO = 3;
    bool peca_no_caminho = false; // Flag para simular um bloqueio.

    // O loop continua enquanto houver passos E o caminho estiver livre.
    for (int i = 1; i <= PASSOS_CAVALO && !peca_no_caminho; i++) {
        
        // Simula um bloqueio no passo 3 para testar o 'break'.
        if (i == 3) {
            printf("  > Caminho bloqueado!\n");
            peca_no_caminho = true; 
            break; // Interrompe o loop na hora.
        }

        // Define se o movimento do passo é vertical ou horizontal.
        if (i <= 2) {
            printf("  Passo %d: Cima\n", i);
        } else {
            printf("  Passo %d: Direita\n", i);
        }
    }
    printf("Fim do movimento do cavalo.\n\n");

    return 0;
}
