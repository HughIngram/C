#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[]);

void copy(char to[], char from[]);

/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getLine(line)) > 0)
        if (len > 81) {
            printf("%s\n", line);
        }
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char line[]) {
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
