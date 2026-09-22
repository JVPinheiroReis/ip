#include <stdio.h>

int main(void) {
    int N;

    scanf("%d", &N);

    int i;
    int j;
    for (i = 0; i < N; i++) {
        char s[50] = "";
        char t[50] = "";

        scanf("%49s", s);
        scanf("%49s", t);

        for (j = 0; s[j] || t[j]; j++) {
            if (s[j]) printf("%c", s[j]);

            if (t[j]) printf("%c", t[j]);
        }

        printf("\n");
    }

    return 0;
}