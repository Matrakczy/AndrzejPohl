#include <stdio.h>

int main() {
    int zmienna = 5;
    int *wskaznik;

    wskaznik = &zmienna;


    *wskaznik = 10;


    printf("Wartosc zmiennej: %d\n", zmienna);


    printf("Wartosc zmiennej przez wskaznik: %d\n", *wskaznik);

    return 0;

}
