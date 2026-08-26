#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int input, prev_input;
        int inter = 1;
        int state = 0; // 0: indefinido, 1: subindo, -1: descendo

        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", &input);

            if (i > 0 && inter) {
                if (input > prev_input) {
                    if (state == 1) {
                        inter = 0;
                    }
                    state = 1;
                }
                else if (input < prev_input) {
                    if (state == -1) {
                        inter = 0;
                    }
                    state = -1;
                }
                else {
                    inter = 0;
                }
            }

            prev_input = input;
        }

        if (inter) {
            printf("Intercalada\n");
        }
        else {
            printf("Nao intercalada\n");
        }
    }

    return 0;
}
