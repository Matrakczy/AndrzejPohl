#include <stdio.h>

// Definicja struktury Point przechowuj¹cej wspó³rzêdne punktu na p³aszczyŸnie
struct Point {
    int x;
    int y;
};

// Funkcja zmieniaj¹ca wspó³rzêdne punktu przechowywanej w strukturze Point
void zmienWspolrzedne(struct Point *point, int new_x, int new_y) {
    point->x = new_x;
    point->y = new_y;
}

// Definicja struktury Rectangle przechowuj¹cej wspó³rzêdne lewego dolnego oraz prawego górnego rogu prostok¹ta
struct Rectangle {
    struct Point bottom_left;
    struct Point top_right;
};

// Funkcja obliczaj¹ca pole prostok¹ta
int poleProstokata(struct Rectangle *rect) {
    int width = rect->top_right.x - rect->bottom_left.x;
    int height = rect->top_right.y - rect->bottom_left.y;
    return width * height;
}

// Funkcja obliczaj¹ca obwód prostok¹ta
int obwodProstokata(struct Rectangle *rect) {
    int width = rect->top_right.x - rect->bottom_left.x;
    int height = rect->top_right.y - rect->bottom_left.y;
    return 2 * (width + height);
}

int main() {
    // Utworzenie instancji struktury Point i zmiana jej wspó³rzêdnych
    struct Point punkt = {3, 4};
    zmienWspolrzedne(&punkt, 5, 6);

    // Wypisanie zmienionych wspó³rzêdnych punktu
    printf("Zmienione wspolrzedne punktu: (%d, %d)\n", punkt.x, punkt.y);

    // Utworzenie instancji struktury Rectangle
    struct Rectangle prostokat = {{1, 2}, {6, 8}};

    // Obliczenie i wypisanie pola prostok¹ta
    printf("Pole prostokata: %d\n", poleProstokata(&prostokat));

    // Obliczenie i wypisanie obwodu prostok¹ta
    printf("Obwod prostokata: %d\n", obwodProstokata(&prostokat));

    return 0;
}
