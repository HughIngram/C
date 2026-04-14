// C=(5/9)(F-32)

#include <stdio.h>

float fahrenheitToCelsius(float fahr);

int main() {
    printf("Farenheit\t|\tCelcius\n");
    float lower = 0;
    float upper = 300;
    float step = 20;

    float fahr = lower;
    while (fahr <= upper) {
        float celsius = fahrenheitToCelsius(fahr);
        printf("%3.0f\t\t\t|\t%3.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

float fahrenheitToCelsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}