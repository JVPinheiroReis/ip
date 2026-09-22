#include <stdio.h>

int main(void) {
    int l, h, lb, vb;

    scanf("%d %d %d %d", &l, &h, &lb, &vb);

    printf("P2\n");
    printf("%d %d\n", l, h);
    printf("255\n");

    int i, j;
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= l; j++) {
            if (j == l) {
                printf("%d", vb);
            }
            else if ((i <= lb || h - lb + 1 <= i) ||
                     (j <= lb || l - lb + 1 <= j)) {
                printf("%d ", vb);
            }
            else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }

    return 0;
}