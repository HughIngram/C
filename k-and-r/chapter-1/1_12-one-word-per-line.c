#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state = IN;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (state == IN) {
                printf("\n");
            }
            state = OUT;
        } else {
            state = IN;
            printf("%c", c);
        }
    }
    return 0;
}
