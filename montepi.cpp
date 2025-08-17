#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long long n, i;
    long long inside = 0;
    double x, y;

    n = 10000000;

    // Generar números aleatorios
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;  // número aleatorio entre 0 y 1
        y = (double) rand() / RAND_MAX;

        if (x * x + y * y <= 1.0) {
            inside++;
        }
    }

    double pi_estimate = 4.0 * (double) inside / (double) n;

    printf("Aproximación de pi con %lld puntos: %.10f\n", n, pi_estimate);

    return 0;
}
