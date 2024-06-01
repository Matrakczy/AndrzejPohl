#include <stdio.h>

// Definicja funkcji modyfikuj�cej warto�� zmiennej typu float przez wska�nik
void modyfikuj(float *ptr) {
    // Podwajamy warto�� zmiennej wskazywanej przez wska�nik
    *ptr *= 2;
}

int main() {
    float zmienna = 3.14; // Deklaracja zmiennej typu float i przypisanie warto�ci 3.14
    float *wskaznik = &zmienna; // Deklaracja i inicjalizacja wska�nika

    // Wywo�anie funkcji modyfikuj�cej warto�� zmiennej przez wska�nik
    modyfikuj(wskaznik);

    // Wypisanie nowej warto�ci zmiennej
    printf("Nowa warto�� zmiennej: %.2f\n", zmienna);

    return 0;
}
