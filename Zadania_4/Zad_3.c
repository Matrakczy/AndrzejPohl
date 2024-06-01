#include <stdio.h>

// Funkcja zamieniaj�ca elementy miejscami
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja generuj�ca permutacje
void generatePermutations(char str[], int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Wy�wietlamy permutacj�
        return;
    }

    for (int i = start; i <= end; i++) {
        // Zamieniamy elementy miejscami
        swap(&str[start], &str[i]);
        // Rekurencyjnie generujemy permutacje dla pozosta�ych element�w
        generatePermutations(str, start + 1, end);
        // Przywracamy pierwotny stan
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[] = "ABC"; // Tw�j ci�g znak�w
    int n = sizeof(str) / sizeof(str[0]);
    generatePermutations(str, 0, n - 1);
    return 0;
}
