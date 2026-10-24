#include <stdio.h>
#include <string.h>

#define MAX_TEXT 2048
#define MAX_WORDS (MAX_TEXT / 2 + 1)
#define DELIMS " .,!?()[]{}"

int main(void) {
    char *tok;
    int i, j, wc = 0;
    char text[MAX_TEXT + 2];
    char *words[MAX_WORDS];
    int counts[MAX_WORDS] = {0};

    if (fgets(text, sizeof text, stdin) == NULL) {
        return 0;
    }
    text[strcspn(text, "\r\n")] = '\0';

    for (tok = strtok(text, DELIMS); tok != NULL && wc < MAX_WORDS;
         tok = strtok(NULL, DELIMS)) {
        words[wc++] = tok;
    }

    for (i = 0; i < wc; i++) {
        if (counts[i] == 0) {
            int c = 1;
            for (j = i + 1; j < wc; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    c++;
                }
            }
            for (j = i; j < wc; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    counts[j] = c;
                }
            }
        }
        printf("(%s)%d\n", words[i], counts[i]);
    }

    return 0;
}