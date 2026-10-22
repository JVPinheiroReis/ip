#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define AGUA ' '
#define NAVIO '@'
#define EXPLOSAO '*'
#define FALHA '-'

void mostra_tabuleiro(char **Tab, int nl, int nc, int mostrar_navios) {
    int l, c;
    /**
     *   0 1 2
     * A| | | |
     * B| | | |
     * C| | | |
     * =========
     * A| | | |
     * B| | | |
     * C| | | |
     *   0 1 2
     */
    if (!mostrar_navios) {
        printf("  ");
        for (c = 0; c < nc; c++)
            printf("%d ", c);
        printf("\n");
    }

    for (l = 0; l < nl; l++) {
        printf("%c|", 'A' + l);
        for (c = 0; c < nc; c++) {
            if (Tab[l][c] == NAVIO && !mostrar_navios) printf("%c|", AGUA);
            else printf("%c|", Tab[l][c]);
        }
        printf("\n");
    }

    if (mostrar_navios) {
        printf("  ");
        for (c = 0; c < nc; c++)
            printf("%d ", c);
        printf("\n");
    }
}

void screen(char **PC, char **J, int nl, int nc) {
    int c;
    mostra_tabuleiro(PC, nl, nc, 0);
    printf("==");
    for (c = 0; c < nc; c++)
        printf("==");
    printf("\n");
    mostra_tabuleiro(J, nl, nc, 1);
}

int sorteia(int min, int max) {
    int n = rand();
    return n % (max - min + 1) + min;
}

void sorteia_tabuleiro(char **Tab, int nl, int nc, int nv) {
    int n = 0;
    int l, c;
    while (n < nv) {
        l = sorteia(0, nl - 1);
        c = sorteia(0, nc - 1);
        if (Tab[l][c] == AGUA) {
            Tab[l][c] = NAVIO;
            n++;
        }
    }
}

void init_tabuleiro(char **Tab, int nl, int nc) {
    int l, c;
    for (l = 0; l < nl; l++) {
        for (c = 0; c < nc; c++) {
            Tab[l][c] = AGUA;
        }
    }
}

char **cria_tabuleiro(int nl, int nc) {
    int i;
    char **Tab = NULL;
    Tab = (char **)malloc(nl * sizeof(char *));
    for (i = 0; i < nl; i++) {
        Tab[i] = (char *)malloc(nc * sizeof(char));
    }
    return Tab;
}

void libera_tabuleiro(char **Tab, int nl) {
    int l;
    for (l = 0; l < nl; l++)
        free(Tab[l]);
    free(Tab);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char uppercase(char c) {
    if ('a' <= c && c <= 'z') {
        return c + 'A' - 'a';
    }
    return c;
}

int main() {
    char **TabPC = NULL;
    char **TabJ = NULL;
    int nl = 5, nc = 8;
    int nv = 7;
    int l, c;
    char ch;

    // primeira jogada: 1 para J, 0 para PC
    int jogada = 1;

    srand(time(0));

    TabPC = cria_tabuleiro(nl, nc);
    TabJ = cria_tabuleiro(nl, nc);

    init_tabuleiro(TabPC, nl, nc);
    init_tabuleiro(TabJ, nl, nc);

    sorteia_tabuleiro(TabPC, nl, nc, nv);
    sorteia_tabuleiro(TabJ, nl, nc, nv);

    do {
        clearScreen();
        screen(TabPC, TabJ, nl, nc);
        sleep(1);
        if (jogada) {
            // Jogador
            printf("Jogada: ");
            scanf(" %c%d", &ch, &c);

            ch = uppercase(ch);
            l = ch - 'A';

            if (TabPC[l][c] == NAVIO) TabPC[l][c] = EXPLOSAO;
            else if (TabPC[l][c] == AGUA) TabPC[l][c] = FALHA;
        }
        else {
            // PC
            l = sorteia(0, nl - 1);
            c = sorteia(0, nc - 1);

            if (TabJ[l][c] == NAVIO) TabJ[l][c] = EXPLOSAO;
            else if (TabJ[l][c] == AGUA) TabJ[l][c] = FALHA;
        }
        jogada = !jogada;
    }
    while (1);

    libera_tabuleiro(TabPC, nl);
    libera_tabuleiro(TabJ, nl);

    return 0;
}