#include <stdio.h>

/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

int getLine(char line[]);

#define TAB_LENGTH = 4;
#define MAXLINE 1000 /* maximum input line length */

int main() {
    char line[MAXLINE]; /* current input line */
    while (getLine(line) > 0) {
        printf("input: %s", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char line[]) {
    int c = 0;
    int i = 0;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = (char) c;
    if (c == '\n') {
        line[i] = (char) c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
