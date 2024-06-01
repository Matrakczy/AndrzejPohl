#include <stdio.h>

// Funkcja zamieniaj¹ca elementy miejscami
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja generuj¹ca permutacje
void generatePermutations(char str[], int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Wyœwietlamy permutacjê
        return;
    }

    for (int i = start; i <= end; i++) {
        // Zamieniamy elementy miejscami
        swap(&str[start], &str[i]);
        // Rekurencyjnie generujemy permutacje dla pozosta³ych elementów
        generatePermutations(str, start + 1, end);
        // Przywracamy pierwotny stan
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[] = "ABC"; // Twój ci¹g znaków
    int n = sizeof(str) / sizeof(str[0]);
    generatePermutations(str, 0, n - 1);
    return 0;
}
