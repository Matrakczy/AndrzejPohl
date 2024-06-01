#include <stdio.h>

// Definicja unii
union Dane {
    int liczba_calkowita;
    float liczba_zmiennoprzecinkowa;
    char znak;
};

int main() {
    // Inicjalizacja unii
    union Dane moja_unia;

    // Przechowywanie wartoœci typu int
    moja_unia.liczba_calkowita = 42;
    printf("Wartosc typu int: %d\n", moja_unia.liczba_calkowita);

    // Przechowywanie wartoœci typu float
    moja_unia.liczba_zmiennoprzecinkowa = 3.14;
    printf("Wartosc typu float: %f\n", moja_unia.liczba_zmiennoprzecinkowa);

    // Przechowywanie pojedynczego znaku
    moja_unia.znak = 'A';
    printf("Znak: %c\n", moja_unia.znak);

    return 0;
}
