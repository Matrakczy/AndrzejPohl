#include <stdio.h>

// Funkcja do dodawania elementu na okreœlonym indeksie
void add_element(int array[], int size, int index, int value) {
    if (index < 0 || index >= size) {
        printf("B³¹d: Nieprawid³owy indeks.\n");
        return;
    }

    // Przesuniêcie elementów w prawo, aby zrobiæ miejsce na nowy element
    for (int i = size - 1; i > index; i--) {
        array[i] = array[i - 1];
    }

    // Dodanie nowego elementu na okreœlonym indeksie
    array[index] = value;
}

int main() {
    int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int index = 3; // Indeks, na którym chcemy dodaæ element
    int value = 99; // Wartoœæ nowego elementu

    // Wywo³anie funkcji dodaj¹cej element
    add_element(myArray, size, index, value);

    // Wyœwietlenie tablicy po dodaniu elementu
    printf("Tablica po dodaniu elementu:\n");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
