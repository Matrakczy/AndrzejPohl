#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Struktura do przechowywania informacji o grze
struct Game {
    int red;
    int green;
    int blue;
};

// Funkcja do rozwi�zania problemu
void solveGame(struct Game *game) {
    int power = game->red * game->green * game->blue;
    printf("Moc zestawu kostek: %d\n", power);
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        perror("Nie mo�na otworzy� pliku");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    struct Game game;
    int inGame = 0; // Flaga okre�laj�ca, czy znajdujemy si� w trakcie gry

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Gra") != NULL) { // Sprawdzanie, czy linia zawiera "Gra"
            if (!inGame) { // Je�li nie jeste�my w trakcie gry, oznacz pocz�tek gry
                inGame = 1;
                printf("Rozpocz�cie gry\n");
                memset(&game, 0, sizeof(game)); // Zerowanie danych gry
            } else { // Je�li jeste�my ju� w trakcie gry, rozwi�� problem
                solveGame(&game);
                inGame = 0; // Oznacz koniec gry
                printf("Koniec gry\n");
            }
        } else { // Je�li linia nie zawiera "Gra", analizuj informacje o grze
            int red, green, blue;
            if (sscanf(line, "%d czerwony, %d zielony, %d niebieskie", &red, &green, &blue) == 3) {
                game.red += red;
                game.green += green;
                game.blue += blue;
            }
        }
    }

    fclose(file);
    return 0;
}
