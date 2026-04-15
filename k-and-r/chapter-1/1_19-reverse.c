/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[]);

int main() {
    int len;
    char line[MAXLINE]; /* current input line */
    while ((len = getLine(line)) > 0) {
        printf("%s", line);
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
