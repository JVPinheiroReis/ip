#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int i;
    int j;
    int p = 0;
    for (i = 1; i <= 6; i++) {
        for (j = 1; j <= 6; j++) {
            if (i + j == n && i != j) {
                p++;
                printf("D1: %d, D2: %d\n", i, j);
            }
        }
    }

    if (p == 0) {
        printf("Combinacao impossivel\n");
        return 0;
    }

    printf("Ha %d possibilidades\n", p);

    return 0;
}
