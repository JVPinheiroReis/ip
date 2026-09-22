#include <stdio.h>

void swap(int *e1, int *e2) {
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void bubble_sort(int *v, int n) {
    int i, c;
    do {
        c = 0;
        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(&v[i], &v[i + 1]);
                c = 1;
            }
        }
    }
    while (c != 0);
}

int main() {
    int n;

    scanf("%d", &n);

    int m[n][n];

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int tmp_v[n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            tmp_v[j] = m[j][i];
        }

        bubble_sort(tmp_v, n);

        for (j = 0; j < n; j++) {
            m[j][i] = tmp_v[j];
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