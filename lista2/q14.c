#include <stdio.h>

int main(void) {
    int n;
    int i, j;

    scanf("%d", &n);

    int m[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int mt[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mt[i][j] = m[j][i];
        }
    }

    int tr = 0;
    for (i = 0; i < n; i++) {
        tr += m[i][i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] *= tr;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] += mt[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}