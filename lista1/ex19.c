#include <stdio.h>

int main(void) {
    int x1, x2, x3;

    scanf("%d %d %d", &x1, &x2, &x3);

    int i = 2;
    int mmc = 1;
    while (x1 > 1 || x2 > 1 || x3 > 1) {
        if (x1 % i == 0 || x2 % i == 0 || x3 % i == 0) {
            printf("%d %d %d :%d\n", x1, x2, x3, i);

            mmc *= i;

            if (x1 % i == 0)
                x1 /= i;
            if (x2 % i == 0)
                x2 /= i;
            if (x3 % i == 0)
                x3 /= i;
        }
        else {
            i++;
        }
    }

    printf("MMC: %d\n", mmc);

    return 0;
}
