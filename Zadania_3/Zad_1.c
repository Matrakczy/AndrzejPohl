#include <stdio.h>

// Funkcja do obliczania wspó³czynnika Newtona (nCr)
int oblicz_wspolczynnik(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    return oblicz_wspolczynnik(n - 1, r - 1) + oblicz_wspolczynnik(n - 1, r);
}

// Funkcja do wyœwietlania trójk¹ta Pascala
void wyswietl_trojkat_pascala(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", oblicz_wspolczynnik(i, j));
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &N);

    wyswietl_trojkat_pascala(N);

    return 0;
}
