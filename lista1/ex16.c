#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n < 0 || n > 255) {
        printf("Numero invalido!\n");
        return 0;
    }

    int i;
    for (i = 128; i >= 1; i /= 2) {
        if (n >= i) {
            printf("1");
            n -= i;
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}
