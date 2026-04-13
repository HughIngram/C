#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int characterFrequencies[256];
    for (int i = 0; i < 256; ++i) {
        characterFrequencies[i] = 0;
    }
    int c;
    while ((c = getchar()) != EOF) {
        ++characterFrequencies[c];
    }

    for (int i = '!'; i < '~'; ++i) {
        if (characterFrequencies[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < characterFrequencies[i]; ++j) {
                printf("x");
            }
            printf("\n");
        }
    }
    return 0;
}
