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
    int spaces = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];

        if (c == ' ') {
            spaces++;
            col++;
            if (col % TAB_LENGTH == 0) {
                printf("\t");
                spaces = 0;
            }
        } else if (c == '\t') {
            printf("\t");
            col += TAB_LENGTH - (col % TAB_LENGTH);
            spaces = 0;
        } else {
            while (spaces > 0) {
                printf(" ");
                spaces--;
            }
            printf("%c", c);
            col++;
        }
    }
    while (spaces > 0) {
        printf(" ");
        spaces--;
    }
}
