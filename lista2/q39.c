#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_string_char(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 1;
    }
    if (('0' <= c && c <= '9')) {
        return 1;
    }
    return 0;
}

int main(void) {
    int i, j, c;
    char **words = NULL;
    char s[2048 + 1] = {'\0'};

    scanf("%2048[^\n]", s);

    int wc = 0, end = 0, start = 0;
    while (strlen(s + start) > 1) {
        while (!is_string_char(s[start])) {
            start++;
        }

        end = start;

        while (is_string_char(s[end])) {
            end++;
        }

        // alloc a new word
        wc++;
        words = (char **)realloc(words, wc * sizeof(char *));
        words[wc - 1] = (char *)calloc((end - start) + 1, sizeof(char));

        // copy the new word content
        strncpy(words[wc - 1], s + start, end - start);
        words[wc - 1][end - start] = '\0';

        start = end;
    }

    for (i = 0; i < wc; i++) {
        c = 0;
        for (j = 0; j < wc; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                c++;
            }
        }

        printf("(%s)%d\n", words[i], c);
    }

    for (i = 0; i < wc; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}