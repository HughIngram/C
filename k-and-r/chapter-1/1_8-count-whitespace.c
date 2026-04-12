#include <stdio.h>

int main() {
    int c;
    int numberOfSpaces = 0;
    int numberOfLineBreaks = 0;
    int numberOfTabs = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++numberOfSpaces;
        if (c == '\t')
            ++numberOfTabs;
        if (c == '\n')
            ++numberOfLineBreaks;
    }
    printf("\n");
    printf("spaces: %d\n", numberOfSpaces);
    printf("newlines: %d\n", numberOfLineBreaks);
    printf("tabs: %d\n", numberOfTabs);
    return 0;
}