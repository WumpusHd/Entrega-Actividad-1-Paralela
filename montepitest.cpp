#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    long long n = 10000000, i;
    long long inside = 0;
    double x, y;
    clock_t start, end;

    start = clock(); // inicio

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1.0)
            inside++;
    }

    double pi_estimate = 4.0 * (double)inside / n;
    end = clock(); // fin

    double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("π ≈ %.10f\n", pi_estimate);
    printf("Tiempo de CPU: %.5f segundos\n", cpu_time);
    printf("Error absoluto: %.10f\n", fabs(pi_estimate - M_PI));

    return 0;
}