#include <stdio.h>
#include <string.h>


#define MAX_LINE 1000 /* maximum input line length */
#define LINE_BREAK 5 /* output line length limit (including trailing \n) */

int getLine(char inputLine[]);

void foldLine(char inputLine[]);

/* Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

/* Test Cases
 * - (with LINE_BREAK set to 4)
 * - all inputs & outputs end with \n
 * - no input can contain \n in the middle
 * - ignore tabs for now
 * "ab\n" - "ab\n"
 * "\n" -> "\n"
 * "1234\n" -> "1234\n"
 * "12345678\n" -> "123-\n456-\n78\n"
 * "1234      \n" -> "1234\n"
 * "123 456" -> "123\n456\n"
 * "123  456\n" -> "123\n456\n"
 * "12 345" -> "12\n345\n"
 * "     \n" -> "\n"
 * "123 456 789" -> "123\n456\n789\n"
 */
int main() {
    char inputLine[MAX_LINE]; /* current input line */
    int length;
    while ((length = getLine(inputLine)) > 0) {
        printf("length: %d\n", length);
        foldLine(inputLine);
    }
    return 0;
}

int getLine(char inputLine[]) {
    int c = 0;
    int i = 0;
    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        inputLine[i] = (char) c;
    if (c == '\n') {
        inputLine[i] = (char) c;
        ++i;
    }
    inputLine[i] = '\0';
    return i;
}

void foldLine(char inputLine[]) {
    if (strlen(inputLine) < LINE_BREAK) {
        printf("%s", inputLine);
    } else {

    }
}
