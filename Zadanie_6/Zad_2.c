#include <stdio.h>

int main() {
    // Tworzenie tablicy dziesi�ciu liczb ca�kowitych
    int tablica[10];

    // Inicjalizacja tablicy warto�ciami od 0 do 9
    for (int i = 0; i < 10; ++i) {
        tablica[i] = i;
    }

    // U�ywanie wska�nika do wy�wietlenia zawarto�ci tablicy
    int* wskaznik = tablica; // Inicjalizacja wska�nika na pierwszy element tablicy

    for (int i = 0; i < 10; ++i) {
        printf("Element %d: %d\n", i, *wskaznik); // Wy�wietlenie warto�ci elementu
        wskaznik++; // Inkrementacja wska�nika, aby przej�� do kolejnego elementu
    }

    return 0;
}
