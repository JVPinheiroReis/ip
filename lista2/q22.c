#include <stdio.h>

int main(void) {
    int N;

    scanf("%d", &N);

    int m[N + 1][N + 1];

    int i, j;
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N + 1; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int c = 0;

    int k, l;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c = 0;
            for (k = 0; k <= 1; k++) {
                for (l = 0; l <= 1; l++) {
                    if (m[i + k][j + l] == 1) c++;
                }
            }

            if (c >= 2) {
                printf("S");
            }
            else {
                printf("U");
            }
        }
        printf("\n");
    }

    return 0;
}