#include <stdio.h>

int main(void) {
    int M = -1;
    int N = -1;
    char s_sum[7 + 1] = "";

    while (M != 0 && N != 0) {
        scanf("%d %d", &M, &N);

        sprintf(s_sum, "%d", M + N);

        int i;
        for (i = 0; s_sum[i] != '\0'; i++) {
            if (s_sum[i] != '0') {
                printf("%c", s_sum[i]);
            }
        }
        printf("\n");
    }

    return 0;
}