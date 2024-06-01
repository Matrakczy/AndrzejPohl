#include <stdio.h>

// Definicja funkcji modyfikuj¹cej wartoœæ zmiennej typu float przez wskaŸnik
void modyfikuj(float *ptr) {
    // Podwajamy wartoœæ zmiennej wskazywanej przez wskaŸnik
    *ptr *= 2;
}

int main() {
    float zmienna = 3.14; // Deklaracja zmiennej typu float i przypisanie wartoœci 3.14
    float *wskaznik = &zmienna; // Deklaracja i inicjalizacja wskaŸnika

    // Wywo³anie funkcji modyfikuj¹cej wartoœæ zmiennej przez wskaŸnik
    modyfikuj(wskaznik);

    // Wypisanie nowej wartoœci zmiennej
    printf("Nowa wartoœæ zmiennej: %.2f\n", zmienna);

    return 0;
}
