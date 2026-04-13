#include <stdio.h>

int main() {
    int c;
    char lastChar;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else if (c == ' ') {
            if (lastChar != c) {
                putchar(c);
            }
        }
        lastChar = c;
    }
    return 0;
}
