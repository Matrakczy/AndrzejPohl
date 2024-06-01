#include <stdio.h>

// Definicja struktury Point przechowuj�cej wsp�rz�dne punktu na p�aszczy�nie
struct Point {
    int x;
    int y;
};

// Funkcja zmieniaj�ca wsp�rz�dne punktu przechowywanej w strukturze Point
void zmienWspolrzedne(struct Point *point, int new_x, int new_y) {
    point->x = new_x;
    point->y = new_y;
}

// Definicja struktury Rectangle przechowuj�cej wsp�rz�dne lewego dolnego oraz prawego g�rnego rogu prostok�ta
struct Rectangle {
    struct Point bottom_left;
    struct Point top_right;
};

// Funkcja obliczaj�ca pole prostok�ta
int poleProstokata(struct Rectangle *rect) {
    int width = rect->top_right.x - rect->bottom_left.x;
    int height = rect->top_right.y - rect->bottom_left.y;
    return width * height;
}

// Funkcja obliczaj�ca obw�d prostok�ta
int obwodProstokata(struct Rectangle *rect) {
    int width = rect->top_right.x - rect->bottom_left.x;
    int height = rect->top_right.y - rect->bottom_left.y;
    return 2 * (width + height);
}

int main() {
    // Utworzenie instancji struktury Point i zmiana jej wsp�rz�dnych
    struct Point punkt = {3, 4};
    zmienWspolrzedne(&punkt, 5, 6);

    // Wypisanie zmienionych wsp�rz�dnych punktu
    printf("Zmienione wspolrzedne punktu: (%d, %d)\n", punkt.x, punkt.y);

    // Utworzenie instancji struktury Rectangle
    struct Rectangle prostokat = {{1, 2}, {6, 8}};

    // Obliczenie i wypisanie pola prostok�ta
    printf("Pole prostokata: %d\n", poleProstokata(&prostokat));

    // Obliczenie i wypisanie obwodu prostok�ta
    printf("Obwod prostokata: %d\n", obwodProstokata(&prostokat));

    return 0;
}
