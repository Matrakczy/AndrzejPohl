#include <stdio.h>

int main() {
    // Tworzenie tablicy dziesięciu liczb całkowitych
    int tablica[10];

    // Inicjalizacja tablicy wartościami od 0 do 9
    for (int i = 0; i < 10; ++i) {
        tablica[i] = i;
    }

    // Używanie wskaźnika do wyświetlenia zawartości tablicy
    int* wskaznik = tablica; // Inicjalizacja wskaźnika na pierwszy element tablicy

    for (int i = 0; i < 10; ++i) {
        printf("Element %d: %d\n", i, *wskaznik); // Wyświetlenie wartości elementu
        wskaznik++; // Inkrementacja wskaźnika, aby przejść do kolejnego elementu
    }

    return 0;
}
