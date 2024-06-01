#include <stdio.h>

int main() {
    // Tworzenie tablicy dziesiêciu liczb ca³kowitych
    int tablica[10];

    // Inicjalizacja tablicy wartoœciami od 0 do 9
    for (int i = 0; i < 10; ++i) {
        tablica[i] = i;
    }

    // U¿ywanie wskaŸnika do wyœwietlenia zawartoœci tablicy
    int* wskaznik = tablica; // Inicjalizacja wskaŸnika na pierwszy element tablicy

    for (int i = 0; i < 10; ++i) {
        printf("Element %d: %d\n", i, *wskaznik); // Wyœwietlenie wartoœci elementu
        wskaznik++; // Inkrementacja wskaŸnika, aby przejœæ do kolejnego elementu
    }

    return 0;
}
