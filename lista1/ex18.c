#include <stdio.h>

int rev_n(int n) {
    int r = 0;

    r += ((n / 100) % 10) * 1;
    r += ((n / 10) % 10) * 10;
    r += ((n / 1) % 10) * 100;

    return r;
}

int main(void) {
    int n, in1, in2;

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &in1, &in2);

        int rev_1 = rev_n(in1);
        int rev_2 = rev_n(in2);
        if (rev_1 > rev_2) {
            printf("%d\n", rev_1);
        }
        else {
            printf("%d\n", rev_2);
        }
    }

    return 0;
}
