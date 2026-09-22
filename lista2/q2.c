#include <stdio.h>

int get_n_leds(char n) {
    if (n == '1') return 2;
    if (n == '2') return 5;
    if (n == '3') return 5;
    if (n == '4') return 4;
    if (n == '5') return 5;
    if (n == '6') return 6;
    if (n == '7') return 3;
    if (n == '8') return 7;
    if (n == '9') return 6;
    if (n == '0') return 6;
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

        scanf("%s", n);

        for (j = 0; n[j]; j++) {
            t += get_n_leds(n[j]);
        }

        printf("%d leds\n", t);
    }

    return 0;
}