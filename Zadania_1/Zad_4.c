#include <stdio.h>

int suma_wielokrotnosci(int n) {
    // Inicjalizacja sumy
    int suma = 0;

    // Sprawdzenie, czy liczba jest ujemna
    if (n < 0) {
        return 0;
    }

    // Iteracja przez wszystkie liczby poni¿ej n
    for (int i = 0; i < n; i++) {
        // Sprawdzenie, czy liczba jest wielokrotnosci¹ 3 lub 5
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }

    return suma;
}

int main() {
    int podana_liczba = 10;
    int wynik = suma_wielokrotnosci(podana_liczba);
    printf("Suma wielokrotnosci 3 i 5 ponizej %d wynosi %d.\n", podana_liczba, wynik);
    return 0;
}
