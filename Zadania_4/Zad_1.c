#include <stdio.h>

// Funkcja obliczaj¹ca silniê
unsigned long long factorial(unsigned int n) {
    if (n == 0) {
        return 1; // Silnia z 0 jest równa 1
    } else {
        return n * factorial(n - 1); // Rekurencyjne obliczanie silni
    }
}

int main() {
    unsigned int number = 5; // Przyk³adowa liczba dla której obliczamy silniê
    unsigned long long result = factorial(number);
    printf("Silnia z %u wynosi %llu\n", number, result);
    return 0;
}
