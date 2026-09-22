#include <stdio.h>

int main(void) {
    int n, m;

    scanf(" %d %d", &n, &m);

    int mt[n][m];

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %d", &mt[i][j]);
        }
    }

    int r_i = -1;
    int r_j = -1;
    int u, d, l, r;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (mt[i][j] == 1111) {
                u = i - 1 >= 0 ? mt[i - 1][j] : mt[i - 1 + n][j];
                d = i + 1 < n ? mt[i + 1][j] : mt[i + 1 - n][j];
                l = j - 1 >= 0 ? mt[i][j - 1] : mt[i][j - 1 + m];
                r = j + 1 < m ? mt[i][j + 1] : mt[i][j + 1 - m];

                if (u == 4 && d == 8 && l == 0 && r == 0) {
                    r_i = i;
                    r_j = j;

                    break;
                }
            }
        }
    }

    if (r_i == -1 && r_j == -1) {
        printf("WALLY NAO ESTA NA MATRIZ\n");
    }
    else {
        printf("%d %d\n", r_i, r_j);
    }

    return 0;
}