#include <stdio.h>
#define MAXLINE 10/* maximum input line length */

int getLine(char line[]);

void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len; /* current line length */
    int max = 0; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    while ((len = getLine(line)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {
        /* there was a line */
        printf("length: %d\n", max);
        printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
