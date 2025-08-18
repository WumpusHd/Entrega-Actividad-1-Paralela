#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cmath>

using ull = unsigned long long;
using namespace std;

void worker(ull tosses, ull &inside) {
    unsigned int seed = time(NULL) ^ (uintptr_t)&inside;
    ull local_inside = 0;
    for (ull i = 0; i < tosses; i++) {
        double x = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        double y = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        if (x * x + y * y <= 1.0)
            local_inside++;
    }
    inside = local_inside;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <num_hilos> <num_lanzamientos>\n";
        return 1;
    }

    int num_threads = stoi(argv[1]);
    ull total_tosses = stoull(argv[2]);
    ull tosses_per_thread = total_tosses / num_threads;

    vector<thread> threads;
    vector<ull> results(num_threads, 0);

    time_t start = time(NULL); // inicio en segundos

    for (int i = 0; i < num_threads; i++)
        threads.emplace_back(worker, tosses_per_thread, ref(results[i]));

    for (auto &t : threads)
        t.join();

    time_t end = time(NULL); // fin

    ull total_inside = 0;
    for (auto r : results)
        total_inside += r;

    double pi = 4.0 * (double)total_inside / (tosses_per_thread * num_threads);

    cout << "π ≈ " << pi << "\n";
    cout << "Tiempo real: " << difftime(end, start) << " segundos\n";
    cout << "Error absoluto: " << fabs(pi - M_PI) << "\n";

    return 0;
}
