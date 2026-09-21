#include <stdio.h>

char lowercase(char c) {
    if ('A' <= c && c <= 'Z') {
        return c + 'a' - 'A';
    }
    else {
        return c;
    }
}

int main(void) {
    char s[100 * 50] = "\0";

    scanf("%[^\n]%*c", s);

    int ac = 0;
    char c = '\0';
    char p1_c = '\0';
    char p2_c = '\0';

    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (i == 0 || s[i] == ' ') {
            if (i == 0)
                c = lowercase(s[i]);
            else if (s[i] == ' ')
                c = lowercase(s[i + 1]);

            if (c == p1_c && p1_c != p2_c) {
                ac++;
            }

            p2_c = p1_c;
            p1_c = c;
        }
    }

    printf("%d", ac);

    return 0;
}