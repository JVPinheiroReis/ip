#include <stdio.h>

int str_len(char s[]) {
    int r = 0;

    while (s[r] != '\0') {
        r++;
    }

    return r;
}

int main(void) {
    int n;

    scanf("%d%*c", &n);

    int i;
    int j;
    char c;
    int s_size;
    for (i = 0; i < n; i++) {
        char s[1000 + 1] = "";
        char t[1000 + 1] = "";

        scanf("%[^\n]%*c", s);

        int s_size = str_len(s);

        for (j = 0; s[j] != '\0'; j++) {
            c = s[j];
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                s[j] = c + 3;
            }
            else {
                s[j] = c;
            }
        }

        for (j = 0; j < s_size; j++) {
            t[j] = s[(s_size - 1) - j];
        }

        for (j = (s_size / 2); j < s_size; j++) {
            t[j]--;
        }

        printf("%s\n", t);
    }

    return 0;
}