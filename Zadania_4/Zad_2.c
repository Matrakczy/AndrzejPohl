#include <stdio.h>

// Funkcja rekurencyjna do wyszukiwania binarnego
int wyszukiwanie_binarne(int tab[], int lewy, int prawy, int szukany) {
    if (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        // Jeœli znaleziono szukany element, zwracamy jego indeks
        if (tab[srodek] == szukany)
            return srodek;

        // Jeœli szukany element jest mniejszy, przeszukujemy lew¹ czêœæ tablicy
        if (tab[srodek] > szukany)
            return wyszukiwanie_binarne(tab, lewy, srodek - 1, szukany);

        // W przeciwnym razie przeszukujemy praw¹ czêœæ tablicy
        return wyszukiwanie_binarne(tab, srodek + 1, prawy, szukany);
    }

    // Element nie zosta³ znaleziony
    return -1;
}

int main() {
    int tablica[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    int szukany_element = 9;

    int indeks = wyszukiwanie_binarne(tablica, 0, rozmiar - 1, szukany_element);

    if (indeks != -1)
        printf("Element %d znajduje sie na indeksie %d.\n", szukany_element, indeks);
    else
        printf("Element %d nie zosta³ znaleziony w tablicy.\n", szukany_element);

    return 0;
}
