#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int i;
    int input;
    int prev_input = 0;
    int count = 0;
    int max_count = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &input);

        if (i > 0 && input > prev_input) {
            count++;
        }
        else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
        }

        prev_input = input;
    }

    printf("O comprimento do segmento crescente maximo e: %d\n", max_count);

    return 0;
}
