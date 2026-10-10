#include <stdio.h>

int main(void) {
    int n;

    int hold_n;

    int cp = 0;
    int ci = 0;
    int cs = 0;

    int max_cs = 0;
    int max_cs_n;

    scanf("%d", &n);

    while (n != 0) {
        hold_n = n;

        printf("%d: ", n);

        while (n != 1) {
            if (cs == 0) {
                printf("%d", n);
            }
            else {
                if (n % 2 == 0) {
                    n /= 2;
                }
                else {
                    n *= 3;
                    n += 1;
                }

                printf(", %d", n);
            }

            if (n % 2 == 0) {
                cp++;
            }
            else {
                ci++;
            }

            cs++;
        }

        if (cs > max_cs) {
            max_cs = cs;
            max_cs_n = hold_n;
        }

        printf("\n");
        printf("Pares: %d, Impares: %d\n", cp, ci);

        cp = 0;
        ci = 0;
        cs = 0;

        scanf("%d", &n);
    }

    printf("Maior sequencia N=%d com %d elementos\n", max_cs_n, max_cs);

    return 0;
}