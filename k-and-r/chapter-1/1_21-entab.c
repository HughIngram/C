#include <stdio.h>

#define TAB_LENGTH 4
#define MAX_LINE 1000 /* maximum input line length */

int getLine(char line[]);

void entab(char line[]);

/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */
int main() {
    char line[MAX_LINE]; /* current input line */
    while (getLine(line) > 0) {
        entab(line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char line[]) {
    int c = 0;
    int i = 0;
    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = (char) c;
    if (c == '\n') {
        line[i] = (char) c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void entab(char line[]) {
    int col = 0;
    int spacesSinceLastTabStop = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\t') {
            printf("\t");
            spacesSinceLastTabStop = 0;
            col += TAB_LENGTH;
        } else if (line[i] == ' ') {
            if (spacesSinceLastTabStop == TAB_LENGTH) {
                printf("\t");
                spacesSinceLastTabStop = 0;
                col += TAB_LENGTH;
            } else {
                spacesSinceLastTabStop++;
                col++;
            }
        } else {
            for (; spacesSinceLastTabStop > 0; spacesSinceLastTabStop--) {
                printf(" ");
                col++;
            }
            printf("%c", line[i]);
        }
    }
}
