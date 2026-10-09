#include <stdio.h>

int potencia(int n, int e) {
    int tmp = 1;

    int i;
    for (i = 0; i < e; i++) {
        tmp *= n;
    }

    return tmp;
}

int encontra_caracter(const char *str, char c) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

double ascii2double(const char *str) {
    int n;

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            n *= -1;
            break;
        }
        if ('0' <= str[i] && str[i] <= '9') {
            n += (str[i] - '0') * potencia(10, i);
        }
    }

    n /= potencia(10, (sizeof(str) - 1) - encontra_caracter(str, '.'));

    return n;
}

double string2double(const char *str) {
    int pos_e = encontra_caracter(str, 'e') + encontra_caracter(str, 'E') + 1;

    int i;
    float n = 0;
    int e = 0;

    char s_n[128] = "\0";
    for (i = 0; i <= pos_e - 1; i++) {
        s_n[i] = str[(pos_e - 1) - i];
    }

    n = ascii2double(s_n);

    char s_e[128] = "\0";
    for (i = 0; i <= pos_e - 1; i++) {
        s_e[i] = str[(pos_e - 1) - i];
    }

    e = ascii2double(s_e);

    if (pos_e == -1) {
        return n;
    }

    printf("%d\n", e);

    return n * potencia(10, e);
}

int main(void) {
    char s[128] = "\0";

    scanf("%[^\n]%*c", s);

    printf("%.3lf\n", string2double(s));

    return 0;
}