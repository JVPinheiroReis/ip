#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_letter(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 1;
    }
    return 0;
}

int main(void) {
    int i;
    char **words;
    char s[2048 + 1] = {'\0'};

    scanf("%2048[^\n]", s);

    int wc = 0, end = 0, start = 0;
    while (end < strlen(s)) {
        while (is_letter(s[end])) {
            end++;
        }
        wc++;

        words = realloc(words, wc);
        words[wc - 1] = (char *)malloc((end - start + 1) * sizeof(char));

        strncpy(words[wc - 1], s + start, end - start + 1);

        while (!is_letter(s[end]) && s[end] != '\0') {
            end++;
        }
        start = end;
    }

    for (i = 0; i < wc; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}