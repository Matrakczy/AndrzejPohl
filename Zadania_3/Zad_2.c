#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja do alokacji dynamicznej macierzy dwuwymiarowej
int** alokuj_macierz(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Funkcja do wype³niania macierzy losowymi liczbami
void wypelnij_macierz(int** matrix, int rows, int cols) {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // Losowa liczba od 0 do 99
        }
    }
}

// Funkcja do wyœwietlania zawartoœci macierzy
void wyswietl_macierz(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Funkcja do zwalniania zaalokowanej pamiêci
void zwolnij_pamiec(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    printf("Podaj liczbe wierszy: ");
    scanf("%d", &rows);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &cols);

    int** moja_macierz = alokuj_macierz(rows, cols);
    wypelnij_macierz(moja_macierz, rows, cols);

    printf("Zawartosc macierzy:\n");
    wyswietl_macierz(moja_macierz, rows, cols);

    zwolnij_pamiec(moja_macierz, rows);

    return 0;
}
