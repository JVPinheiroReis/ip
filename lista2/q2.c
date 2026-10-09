#include <stdio.h>

int get_n_leds(char n) {
    static const int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    if (n < '0' || n > '9') {
        return 0;
    }

    return leds[n - '0'];
}

int main(void) {
    int N;

    scanf("%d", &N);

    if (N < 1 || N > 1000) {
        return 0;
    }

    int i;
    int j;

    for (i = 0; i < N; i++) {
        int t = 0;
        char n[100] = "";

        scanf("%99s", n);

        for (j = 0; n[j]; j++) {
            t += get_n_leds(n[j]);
        }

        printf("%d leds\n", t);
    }

    return 0;
}
