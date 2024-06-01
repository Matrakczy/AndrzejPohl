#include <stdio.h>

// Funkcja obliczaj�ca silni�
unsigned long long factorial(unsigned int n) {
    if (n == 0) {
        return 1; // Silnia z 0 jest r�wna 1
    } else {
        return n * factorial(n - 1); // Rekurencyjne obliczanie silni
    }
}

int main() {
    unsigned int number = 5; // Przyk�adowa liczba dla kt�rej obliczamy silni�
    unsigned long long result = factorial(number);
    printf("Silnia z %u wynosi %llu\n", number, result);
    return 0;
}
