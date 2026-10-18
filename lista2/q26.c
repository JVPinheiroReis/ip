#include <stdio.h>

int main(void) {
    int N, M;

    scanf("%d %d", &N, &M);

    int m[N][M];

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int min = m[0][0];
    int max = m[0][0];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
            else if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }

    int c_min = 0;
    int c_max = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (m[i][j] == min) {
                c_min++;
            }
            else if (m[i][j] == max) {
                c_max++;
            }
        }
    }

    printf("%d %.2lf%%\n", min, (double)100 * c_min / (N * M));
    printf("%d %.2lf%%\n", max, (double)100 * c_max / (N * M));

    return 0;
}