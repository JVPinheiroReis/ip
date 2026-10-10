#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    if (n < 3 || n > 1000) {
        return 0;
    }

    int i;
    int cq = 0;
    int sd = 1;
    int max_sd = 1;
    int input = 0;
    int prev_input1 = 0;
    int prev_input2 = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &input);

        if (prev_input1 != 0) {
            if (input < prev_input1) {
                sd++;

                if (sd > max_sd) {
                    max_sd = sd;
                }
            }
            else {
                sd = 1;
            }
        }

        if (prev_input2 != 0) {
            if (input < prev_input1 && prev_input1 < prev_input2) {
                cq++;
            }
        }

        prev_input2 = prev_input1;
        prev_input1 = input;
    }

    printf("Ocorrencias de queda: %d\n", cq);
    printf("Maior sequencia decrescente: %d\n", max_sd);

    if (max_sd >= 4) {
        printf("Queda prolongada: SIM\n");
    }
    else {
        printf("Queda prolongada: NAO\n");
    }

    return 0;
}