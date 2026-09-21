#include <stdio.h>
#include <string.h>

int main(void) {
    int N;

    scanf("%d%*c", &N);

    int a, b;
    char s_n[5 + 1];

    int i, j, k;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);

        for (j = a; j <= b; j++) {
            printf("%d", j);
        }

        for (j = b; j >= a; j--) {
            sprintf(s_n, "%d", j);

            for (k = strlen(s_n) - 1; k >= 0; k--) {
                printf("%c", s_n[k]);
            }
        }

        printf("\n");
    }

    return 0;
}