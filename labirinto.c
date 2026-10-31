#include <stdio.h>
#include <stdlib.h>

void desenhar(char **mapa, int largura, int altura, int px, int py, int raio) {
    int i, j;

    system("clear");

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            int dx = j - px;
            int dy = i - py;

            if (dx * dx + dy * dy <= raio * raio) {
                printf("%c", (i == py && j == px) ? '@' : mapa[i][j]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nWASD + ENTER para se mover | Q para sair\n");
}

int main() {
    int largura, altura;
    int i, j;

    // TELA INICIAL
    system("clear");

    printf("========================================\n");
    printf("             LABIRINTITE                \n");
    printf("   (nome ainda em processo criativo)    \n");
    printf("========================================\n");

    printf("\n");

    printf("Voce esta preso em um labirinto escuro e\n");
    printf("precisa encontrar uma maneira de escapar.\n\n");

    printf("OBJETIVO:\n");
    printf("Encontre a saida representada pela letra X.\n");
    printf("Tome cuidado com as paredes representadas por #.\n\n");

    printf("CONTROLES:\n");
    printf("W - Mover para cima\n");
    printf("A - Mover para a esquerda\n");
    printf("S - Mover para baixo\n");
    printf("D - Mover para a direita\n");
    printf("Q - Sair do jogo\n\n");

    printf("INFORMACOES IMPORTANTES:\n");
    printf("- Voce sera representado pelo simbolo @.\n");
    printf("- Sua visao e limitada ao redor do personagem.\n");
    printf("- Pressione ENTER depois de cada movimento.\n");
    printf("- Voce nao pode atravessar paredes.\n\n");

    printf("Boa sorte e tente encontrar a saida!\n");

    printf(
        "\nPressione ENTER para comecar..."); // pq to digitando duas vezes?!?
    getchar();
    getchar();

    // montar o tamanho do labirito
    system("clear");

    printf("========================================\n");
    printf("          CONFIGURACAO DO JOGO           \n");
    printf("========================================\n\n");

    printf("Digite a largura do labirinto: ");
    if (scanf("%d", &largura) != 1) return 1;

    printf("Digite a altura do labirinto: ");
    if (scanf("%d", &altura) != 1) return 1;

    if (largura < 5 || altura < 5) {
        printf("\nO labirinto precisa ter pelo menos 5x5!\n");
        return 1;
    }

    // aloc din nossa de cada dia neh
    char **mapa = malloc(altura * sizeof(char *));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (i = 0; i < altura; i++) {
        mapa[i] = malloc(largura * sizeof(char));

        if (mapa[i] == NULL) {
            printf("Erro ao alocar memoria!\n");

            for (j = 0; j < i; j++) {
                free(mapa[j]);
            }

            free(mapa);
            return 1;
        }
    }

    // criando o mapa
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) {
                mapa[i][j] = '#';
            }
            else {
                mapa[i][j] = ' ';
            }
        }
    }

    // paredes
    if (largura >= 6 && altura >= 6) {
        for (i = 2; i < altura - 1; i++) {
            mapa[i][3] = '#';
        }
    }

    // saida
    mapa[altura - 2][largura - 2] = 'X';

    // posicao do comeco
    int px = 1;
    int py = 1;

    int raio = 3;
    char tecla;

    while (1) {
        desenhar(mapa, largura, altura, px, py, raio);

        if (scanf(" %c", &tecla) != 1) {
            break;
        }

        int nx = px;
        int ny = py;

        if (tecla == 'w' || tecla == 'W') {
            ny--;
        }
        else if (tecla == 's' || tecla == 'S') {
            ny++;
        }
        else if (tecla == 'a' || tecla == 'A') {
            nx--;
        }
        else if (tecla == 'd' || tecla == 'D') {
            nx++;
        }
        else if (tecla == 'q' || tecla == 'Q') {
            break;
        }

        // verificar mov
        if (nx >= 0 && nx < largura && ny >= 0 && ny < altura &&
            mapa[ny][nx] != '#') {
            px = nx;
            py = ny;
        }

        // VERIFICACAO DA SAIDA
        if (mapa[py][px] == 'X') {
            desenhar(mapa, largura, altura, px, py, raio);

            printf("\n========================================\n");
            printf("       PARABENS! VOCE ESCAPOU! Agora nunca mais volte aqui "
                   "\n");
            printf("========================================\n");

            break;
        }
    }

    // Liberar memoria, q tem q ser com a altura
    for (i = 0; i < altura; i++) {
        free(mapa[i]);
    }

    free(mapa);

    return 0;
}