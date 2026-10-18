#include <stdio.h>

int main(void) {
    int ln, cl;

    scanf("%d %d", &ln, &cl);

    int m[ln][cl];

    if (ln <= 0 || 10 < ln || cl <= 0 || 10 < cl) {
        printf("dimensao invalida\n");
        return 0;
    }

    int i, j;
    for (i = 0; i < ln; i++) {
        for (j = 0; j < cl; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int c = 0;
    int first = 1;

    int k, l;
    for (i = 0; i < ln; i++) {
        for (j = 0; j < cl; j++) {
            for (k = 0; k < ln; k++) {
                for (l = 0; l < cl; l++) {
                    if (m[i][j] == m[k][l]) {
                        c++;
                    }
                }
            }

            if (c == 1) {
                if (!first) printf(",");
                printf("%d", m[i][j]);

                first = 0;
            }

            c = 0;
        }
    }

    if (first) {
        printf("sem elementos unicos\n");
    }

    return 0;
}