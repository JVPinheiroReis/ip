#include <stdio.h>

char lowercase(char c) {
    if ('A' <= c && c <= 'Z') return c + ('a' - 'A');

    return c;
}

int main(void) {
    int ac, seq;
    char c, p_c;
    char s[5101];

    while (scanf(" %5100[^\n]", s) == 1) {
        ac = 0;
        seq = 1;
        p_c = '\0';

        int i;
        for (i = 0; s[i] != '\0'; i++) {
            if (i == 0 || s[i] == ' ') {
                c = lowercase(s[i == 0 ? i : i + 1]);

                if (c == p_c) {
                    seq++;
                }
                else {
                    seq = 1;
                }

                if (seq == 2) {
                    ac++;
                }

                p_c = c;
            }
        }

        printf("%d\n", ac);
    }

    return 0;
}