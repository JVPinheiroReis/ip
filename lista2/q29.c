#include <stdio.h>

#define N 257

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
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!in_str(str[i], clr)) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[N] = "";
    char clr[N] = "";

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);

    str_clean(str, clr);

    printf("%s\n", str);

    return 0;
}