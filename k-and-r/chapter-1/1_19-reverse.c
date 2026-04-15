/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[]);

void reverse(char line[]);

int main() {
    char line[MAXLINE]; /* current input line */
    while (getLine(line) > 0) {
        printf("input: %s", line);
        reverse(line);
        printf("output: %s", line);
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

/* reverses the string passed in */
void reverse(char line[]) {
    char tempLine[MAXLINE];
    // copy line into templine, including trailing \n and \0
    int i = 0;
    for (; line[i] != '\0'; i++) {
        tempLine[i] = line[i];
    }
    // subtract 2 as we skip the trailing \n and \0
    int endIndex = i - 2;
    // reverse-copy templine into line
    for (int j = 0; j <= endIndex; j++) {
        line[j] = tempLine[endIndex - j];
    }
}
