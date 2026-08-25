#include <stdio.h>

int main(void) {
    int n, m = 0;

    scanf("%d", &n);

    m += ((n / 100) % 10) * 1;
    m += ((n / 10) % 10) * 10;
    m += ((n / 1) % 10) * 100;

    printf("%d\n", m);

    return 0;
}
