#include <stdio.h>

int main(void) {
    int t = 0;
    int max_t = -64;
    int m[6][6];

    int i;
    int j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int k;
    int l;
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if ((k != 0) || (k == 0 && l == 0)) {
                        t += m[i + k][j + l];
                    }
                }
            }

            if (t > max_t) {
                max_t = t;
            }

            t = 0;
        }
    }

    printf("%d\n", max_t);

    return 0;
}