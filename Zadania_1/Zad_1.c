#include <stdio.h>
#include <conio.h>

int main() {
    char imie[100]; // Przyk�ad: Maksymilian
    printf("Wprowadz swoje imie: ");
    scanf("%s", imie);
    printf("Witaj, %s!\n", imie);

    printf("Nacisnij dowolny klawisz, aby zakonczyc...\n");
    while (!_kbhit()) {
        // Czekaj na wcisni�cie klawisza
    }

    return 0;
}
