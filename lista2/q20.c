#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int v;
    int t = 0;

    int i;
    for (i = 0; i < n; i++) {
        char s1[10000];
        char s2[10000];

        scanf(" %s %s", s1, s2);

        int j;
        for (j = 0; s1[j] != '\0'; j++) {
            if (s2[j] >= s1[j]) {
                v = s2[j] - s1[j];
            }
            else {
                v = 26 + s2[j] - s1[j];
            }

            t += v;
        }

        printf("%d\n", t);

        t = 0;
    }
    return 0;
}