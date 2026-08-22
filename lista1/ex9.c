#include <stdio.h>

int main(void) {
    int n;
    long long int r = 1;

    scanf("%d", &n);

    int i;
    for (i = n; i >= 1; i--) {
        r *= i;
    }

    printf("%d! = %lld\n", n, r);

    return 0;
}
