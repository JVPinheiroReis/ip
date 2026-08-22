#include <stdio.h>

int main(void) {
    unsigned int n;

    scanf("%d", &n);

    int i;
    int input;
    int count = 0;
    int prev_input = 0;
    int prev_max_count = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &input);

        if (input > prev_input) {
            count++;
            if (count > prev_max_count) {
                prev_max_count = count;
            }
        }
        else {
            count = 1;
        }

        prev_input = input;
    }

    printf("O comprimento do segmento crescente maximo e: %d\n",
           prev_max_count);

    return 0;
}
