// F = (C/(5/9) + 32

#include <stdio.h>

int main() {
    printf("Celsius\t|\tFahrenheit\n");
    const float lower = 0.0f;
    const float upper = 300.0f;

    float celsius = lower;
    while (celsius <= upper) {
        const float step = 20.0f;
        const float fahrenheit = celsius / (5.0f / 9.0f) + 32.0f;
        printf("%3.0f\t\t\t|\t%3.1f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}
