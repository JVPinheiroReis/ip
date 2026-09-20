#include <stdio.h>

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);

    int mt[m][n];

    int b;
    int sn = 1;

    int i, j;
    for (i = 0; i < m; i++) {
        if (i % 2 != 0) {
            b = -1;
        }
        else {
            b = 1;
        }

        for (j = 0; j < n; j++) {
            if (b == 1) {
                printf("%d ", 0);
            }
            else {
                printf("%d ", sn);
                sn++;
            }
            b *= -1;
        }

        printf("\n");
    }

    return 0;
}