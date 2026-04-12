#include <stdbool.h>
#include <stdio.h>

int main() {
    int c;
    bool go = true;
    while (go) {
        go = (c= getchar()) != EOF;
        if (!go) {
            printf("%d", EOF);
        }
        putchar(c);
        printf("%d\n", c);
    }
    return 0;
}