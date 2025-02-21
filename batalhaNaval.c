/*
 * Jogo de Batalha Naval com habilidades especiais e navios ocupando 3 posições.
 * O tabuleiro tem 10x10 e os navios podem estar na horizontal, vertical ou diagonal.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 // Definição do tamanho do tabuleiro
 #define SIZE 10
 
 // Definição dos valores do tabuleiro
 #define SHIP 3       // Representação do navio
 #define AFFECTED 5   // Área afetada por habilidades
 #define WATER 0      // Representação da água
 
 // Estrutura para representar um navio
 typedef struct {
     int x, y;          // Coordenadas iniciais do navio
     int orientation;   // Direção do navio (0 = horizontal, 1 = vertical, 2 = diagonal)
 } Ship;
 
 // Função para inicializar o tabuleiro preenchendo todas as posições com água (0)
 void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
     for (int i = 0; i < SIZE; i++) { // Percorre as linhas do tabuleiro
         for (int j = 0; j < SIZE; j++) { // Percorre as colunas do tabuleiro
             tabuleiro[i][j] = WATER; // Define todas as posições como água
         }
     }
 }
 
 // Função para posicionar um navio no tabuleiro de acordo com sua posição inicial e orientação
 void posicionarNavio(int tabuleiro[SIZE][SIZE], Ship ship) {
     for (int i = 0; i < 3; i++) { // O navio sempre ocupa 3 posições
         if (ship.orientation == 0 && ship.y + i < SIZE) { // Verifica se a orientação é horizontal
             tabuleiro[ship.x][ship.y + i] = SHIP; // Posiciona o navio horizontalmente
         } else if (ship.orientation == 1 && ship.x + i < SIZE) { // Verifica se a orientação é vertical
             tabuleiro[ship.x + i][ship.y] = SHIP; // Posiciona o navio verticalmente
         } else if (ship.orientation == 2 && ship.x + i < SIZE && ship.y + i < SIZE) { // Verifica se a orientação é diagonal
             tabuleiro[ship.x + i][ship.y + i] = SHIP; // Posiciona o navio diagonalmente
         }
     }
 }
 
 // Função para exibir o tabuleiro no console
 void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
     for (int i = 0; i < SIZE; i++) { // Percorre as linhas do tabuleiro
         for (int j = 0; j < SIZE; j++) { // Percorre as colunas do tabuleiro
             printf("%d ", tabuleiro[i][j]); // Imprime o valor da posição
         }
         printf("\n"); // Quebra de linha após imprimir cada linha do tabuleiro
     }
 }
 
 // Função principal que inicializa o jogo, posiciona os navios e exibe o tabuleiro
 int main() {
     int tabuleiro[SIZE][SIZE]; // Declaração da matriz representando o tabuleiro
     inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro preenchendo com água
     
     srand(time(NULL)); // Inicializa o gerador de números aleatórios
     
     Ship navios[3]; // Declaração de um array para armazenar os navios
     for (int i = 0; i < 3; i++) { // Laço para gerar e posicionar 3 navios
         navios[i].x = rand() % SIZE; // Define uma posição aleatória na linha
         navios[i].y = rand() % SIZE; // Define uma posição aleatória na coluna
         navios[i].orientation = rand() % 3; // Escolhe uma direção aleatória (horizontal, vertical ou diagonal)
         posicionarNavio(tabuleiro, navios[i]); // Posiciona o navio no tabuleiro
     }
     
     exibirTabuleiro(tabuleiro); // Exibe o tabuleiro final com os navios posicionados
     return 0; // Retorna 0 indicando que o programa foi executado com sucesso
 }
 