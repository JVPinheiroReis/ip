#include <stdio.h>
#define STR_SIZE 128

double potencia(int n, int e) {
    if (e < 0) {
        return 1.0 / potencia(n, -e);
    }

    double tmp = 1;

    int i;
    for (i = 0; i < e; i++) {
        tmp *= n;
    }

    return tmp;
}

int encontra_char(const char *str, char c) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int tamanho_string(const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
    }

    return i;
}

double ascii2double(const char *str) {
    int i, j;
    double n = 0;

    char tmp[STR_SIZE] = "\0";

    i = 0;
    j = 0;
    while (str[j] != '\0') {
        if (str[j] == '.') {
            j++;
            continue;
        }

        tmp[i] = str[j];

        i++;
        j++;
    }

    char c;
    for (i = 0; i <= tamanho_string(tmp) - 1; i++) {
        c = tmp[tamanho_string(tmp) - 1 - i];

        if (c == '-') {
            n *= -1;
            break;
        }
        if ('0' <= c && c <= '9') {
            n += (c - '0') * potencia(10, i);
        }
    }

    if (encontra_char(str, '.') != -1) {
        n /= potencia(10, tamanho_string(str) - 1 - encontra_char(str, '.'));
    }

    if (n == 0) {
        return 0.0;
    }
    return n;
}

double string2double(const char *str) {
    int pos_e = encontra_char(str, 'e');
    if (pos_e == -1) {
        pos_e = encontra_char(str, 'E');
    }

    int i;
    if (pos_e == -1) {
        double n = ascii2double(str);

        return n;
    }
    else {
        char s_n[STR_SIZE] = "\0";
        for (i = 0; i <= pos_e - 1; i++) {
            s_n[i] = str[i];
        }

        double n = ascii2double(s_n);

        char s_e[STR_SIZE] = "\0";
        for (i = pos_e + 1; i <= tamanho_string(str) - 1; i++) {
            s_e[i - (pos_e + 1)] = str[i];
        }

        int e = (int)ascii2double(s_e);

        return n * potencia(10, e);
    }
}

int main(void) {
    char s[STR_SIZE] = "\0";

    scanf("%127[^\n]%*c", s);

    printf("%.3lf\n", string2double(s));

    return 0;
}