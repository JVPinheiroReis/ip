#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++) {
        printf("%d*%d*%d = ", i, i, i);

        int j;
        for (j = (i * i) - i; j <= (i * i) + i; j++) {
            if (j % 2 != 0 && j >= (i * i) + i - 1) {
                printf("%d", j);
            }
            else if (j % 2 != 0) {
                printf("%d+", j);
            }
        }
        printf("\n");
    }

    return 0;
}
