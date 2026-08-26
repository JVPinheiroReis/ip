#include <stdio.h>

int main(void) {
    double n;

    scanf("%lf", &n);

    int i = 1;
    while (n * i != (int)(n * i)) {
        i++;
    }

    printf("%d/%d\n", (int)(n * i), i);

    return 0;
}
