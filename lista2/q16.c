#include <stdio.h>
#include <stdlib.h>

char *corta_string(int n, char *s) {
    char *t = (char *)malloc(n * sizeof(s[0]) + 1);

    int i;
    for (i = 0; i < n; i++) {
        if (s[i] == '\0') {
            break;
        }

        t[i] = s[i];
    }
    t[i] = '\0';

    return t;
}

int main(void) {
    int N;

    scanf("%d", &N);

    int n;
    char s[499 + 1];

    int i, j;
    for (i = 0; i < N; i++) {
        scanf("%d%*c", &n);

        scanf("%[^\n]%*c", s);

        printf("%s", corta_string(n, s));

        printf("\n");
    }

    return 0;
}