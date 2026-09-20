#include <stdio.h>

int ehPermutacao(int m[500][500], int n, int *t) {
    int r = 1;

    *t = 0;
    int ec, el, n1c = 0, n1l = 0;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ec = m[i][j];
            el = m[j][i];

            if ((ec != 0 && ec != 1) || (el != 0 && el != 1)) {
                r = 0;
            }

            if (ec == 1) {
                n1c++;
            }

            if (el == 1) {
                n1l++;
            }

            *t += ec;
        }

        if (n1c != 1 || n1l != 1) {
            r = 0;
        }

        n1c = 0;
        n1l = 0;
    }

    return r;
}

int main(void) {
    int n;
    int t;

    scanf("%d", &n);

    int m[500][500];

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    printf("%d\n", n);

    if (ehPermutacao(m, n, &t)) {
        printf("PERMUTACAO\n");
    }
    else {
        printf("NAO EH PERMUTACAO\n");
    }

    printf("%d\n", t);

    return 0;
}