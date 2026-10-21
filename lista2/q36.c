#include <stdio.h>

int N, K;

void multiplica_matrizes(double m[][N], double n[][N]) {
    int l, c, x, y;
    double t, r[N][N];

    for (l = 0; l < N; l++) {
        for (c = 0; c < N; c++) {
            t = 0;

            x = 0;
            y = 0;
            while (x < N && y < N) {
                t += m[l][x] * n[y][c];

                x++;
                y++;
            }

            r[l][c] = t;
        }
    }

    for (l = 0; l < N; l++) {
        for (c = 0; c < N; c++) {
            m[l][c] = r[l][c];
        }
    }
}

void potencia_matriz(double m[][N], int e) {
    int i, j;
    double hm[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            hm[i][j] = m[i][j];
        }
    }

    for (i = 0; i < e - 1; i++) {
        multiplica_matrizes(m, hm);
    }
}

int main(void) {
    int i, j;

    scanf("%d", &N);

    if (N <= 0 || 10 < N) {
        return 0;
    }

    scanf("%d", &K);

    double m[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    potencia_matriz(m, K);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%s%.3lf", (j > 0) ? " " : "", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}