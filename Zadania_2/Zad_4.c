#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicja struktury Student przechowuj¹cej imiê i ocenê koñcow¹
struct Student {
    char imie[50];
    float ocena;
};

// Funkcja sortuj¹ca tablicê struktur Student wed³ug ocen koñcowych w porz¹dku malej¹cym
void sortujStudentow(struct Student *tablica, int rozmiar) {
    int i, j;
    struct Student temp;

    for (i = 0; i < rozmiar - 1; ++i) {
        for (j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

int main() {
    int liczba_studentow = 100;
    struct Student studenci[100];

    // Inicjacja przyk³adowymi danymi
    for (int i = 0; i < liczba_studentow; ++i) {
        sprintf(studenci[i].imie, "Student%d", i+1);
        studenci[i].ocena = rand() % 51 + 50; // Losowa ocena z zakresu 50-100
    }

    // Wywo³anie funkcji sortuj¹cej
    sortujStudentow(studenci, liczba_studentow);

    // Wypisanie posortowanej listy studentów wraz z ich ocenami
    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < liczba_studentow; ++i) {
        printf("Imie: %s, Ocena: %.2f\n", studenci[i].imie, studenci[i].ocena);
    }

    return 0;
}
