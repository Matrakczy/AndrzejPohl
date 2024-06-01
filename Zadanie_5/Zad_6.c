#include <stdio.h>

// Funkcja do dodawania elementu na okre�lonym indeksie
void add_element(int array[], int size, int index, int value) {
    if (index < 0 || index >= size) {
        printf("B��d: Nieprawid�owy indeks.\n");
        return;
    }

    // Przesuni�cie element�w w prawo, aby zrobi� miejsce na nowy element
    for (int i = size - 1; i > index; i--) {
        array[i] = array[i - 1];
    }

    // Dodanie nowego elementu na okre�lonym indeksie
    array[index] = value;
}

int main() {
    int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int index = 3; // Indeks, na kt�rym chcemy doda� element
    int value = 99; // Warto�� nowego elementu

    // Wywo�anie funkcji dodaj�cej element
    add_element(myArray, size, index, value);

    // Wy�wietlenie tablicy po dodaniu elementu
    printf("Tablica po dodaniu elementu:\n");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
