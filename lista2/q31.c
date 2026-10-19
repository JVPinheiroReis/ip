#include <stdio.h>

int main() {
    int N, M;
    int i, j, k, l;

    scanf("%d", &N);

    int logo[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &logo[i][j]);
        }
    }

    scanf("%d", &M);

    int img[M][M];
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &img[i][j]);
        }
    }

    int c = 0;
    for (i = 0; i < M - N + 1; i++) {
        for (j = 0; j < M - N + 1; j++) {
            c = 0;
            for (k = 0; k < N; k++) {
                for (l = 0; l < N; l++) {
                    if (img[i + k][j + l] == logo[k][l]) {
                        c++;
                    }
                }
            }

            if (c == N * N) {
                printf("sim\n");
                return 0;
            }
        }
    }

    printf("nao\n");

    return 0;
}