#include <stdio.h>

int in_str(char c, char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1;
        }
    }

    return 0;
}

void str_clean(char *str, char *clr) {
    char tmp[256] = "";

    int i;
    int j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!in_str(str[i], clr)) {
            tmp[j++] = str[i];
        }
    }

    for (i = 0; tmp[i] != '\0'; i++) {
        str[i] = tmp[i];
    }
    str[i] = '\0';
}

int main() {
    char str[256];
    char clr[256];

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);

    str_clean(str, clr);

    printf("%s\n", str);

    return 0;
}