#include <stdio.h>

int is_one(char s[]) {
    if (s[0] == 'o' && s[1] == 'n') {
        return 1;
    }
    else if (s[0] == 'o' && s[2] == 'e') {
        return 1;
    }
    else if (s[1] == 'n' && s[2] == 'e') {
        return 1;
    }

    return 0;
}

int is_two(char s[]) {
    if (s[0] == 't' && s[1] == 'w') {
        return 1;
    }
    else if (s[0] == 't' && s[2] == 'o') {
        return 1;
    }
    else if (s[1] == 'w' && s[2] == 'o') {
        return 1;
    }

    return 0;
}

int is_three(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
    }

    if (i == 5) {
        return 1;
    }

    return 0;
}

int main(void) {
    int N;

    scanf("%d%*c", &N);

    int i;
    for (i = 0; i < N; i++) {
        char s[5 + 1] = "";
        scanf("%s", s);

        if (is_one(s)) {
            printf("1\n");
        }
        else if (is_two(s)) {
            printf("2\n");
        }
        else if (is_three(s)) {
            printf("3\n");
        }
    }
}