#include <iostream>
#include <cstdlib>
#include <chrono>

double calculatePi(int upper_bound) {
    double pi_approx = 0.0;
    for (int n = 0; n <= upper_bound; ++n) {
        double signo = (n % 2 == 0) ? 1.0 : -1.0;
        double denominador = 2.0 * n + 1.0;
        pi_approx += signo / denominador;
    }
    pi_approx *= 4.0;
    return pi_approx;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int upper_bound = std::atoi(argv[1]);
    if (upper_bound < 0) {
        std::cout << "El upper_bound debe ser no negativo." << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    double pi_value = calculatePi(upper_bound);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "El valor aproximado de Pi es: " << pi_value << std::endl;
    std::cout << "Tiempo de ejecución: " << duration.count() << " ms" << std::endl;

    return 0;
}