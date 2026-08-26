#include <stdio.h>

int main(void) {
    int n, i, r = 1;
    double input, prev_input;

    while (scanf("%d", &n) == 1 && n > 0) {
        for (i = 0; i < n; i++) {
            scanf("%lf", &input);

            if (i > 0) {
                if (input < prev_input) {
                    r = 0;
                }
            }

            prev_input = input;
        }
        if (r == 1) {
            printf("ORDENADA\n");
        }
        else {
            printf("DESORDENADA\n");
        }

        r = 1;
    }

    return 0;
}
