#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[]);

void copy(char to[], char from[]);

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */
int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getLine(line)) > 0) {
        int indexOfFirstNonBlank = 0;
        // subtract 1 for the trailing linebreak, subtract 1 again for 0 indexing
        for (int j = len - 2; j >= 0; --j) {
            if (line[j] != ' ') {
                indexOfFirstNonBlank = j;
                j = 0; // exit the  loop
            }
        }
        for (int i = 0; i <= indexOfFirstNonBlank; ++i) {
            printf("%c", line[i]);
        }
        printf("\n");
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
