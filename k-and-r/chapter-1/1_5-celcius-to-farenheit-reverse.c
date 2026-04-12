// F = (C/(5/9) + 32

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    printf("Celsius\t|\tFahrenheit\n");

    for (int celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP) {
        const float fahrenheit = celsius / (5.0f / 9.0f) + 32.0f;
        printf("%3d\t\t\t|\t%3.1f\n", celsius, fahrenheit);
    }
}
