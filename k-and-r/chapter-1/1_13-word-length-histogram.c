#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int wordLengths[10];
    for (int i = 0; i < 10; ++i) {
        wordLengths[i] = 0;
    }
    int c;
    int state = IN;
    int wordLength = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++wordLengths[wordLength];
                wordLength = 0;
            }
            state = OUT;
        } else {
            state = IN;
            wordLength++;
        }
    }

    if (wordLength > 0) {
        ++wordLengths[wordLength];
    }

    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < wordLengths[i]; ++j) {
            printf("x");
        }
        printf("\n");
    }
    return 0;
}
