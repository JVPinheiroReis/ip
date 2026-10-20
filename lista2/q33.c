#include <stdio.h>

int main() {
    int n;
    int i, j;

    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("dimensao invalida\n");
        return 0;
    }

    int m[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] != m[j][i] || m[i][j] != m[n - 1 - j][n - 1 - i]) {
                printf("nao bissimetrica\n");
                return 0;
            }
        }
    }

    printf("bissimetrica\n");
    return 0;
}