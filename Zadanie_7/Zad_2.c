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

// Funkcja do rozwi¹zania problemu
void solveGame(struct Game *game) {
    int power = game->red * game->green * game->blue;
    printf("Moc zestawu kostek: %d\n", power);
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        perror("Nie mo¿na otworzyæ pliku");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    struct Game game;
    int inGame = 0; // Flaga okreœlaj¹ca, czy znajdujemy siê w trakcie gry

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Gra") != NULL) { // Sprawdzanie, czy linia zawiera "Gra"
            if (!inGame) { // Jeœli nie jesteœmy w trakcie gry, oznacz pocz¹tek gry
                inGame = 1;
                printf("Rozpoczêcie gry\n");
                memset(&game, 0, sizeof(game)); // Zerowanie danych gry
            } else { // Jeœli jesteœmy ju¿ w trakcie gry, rozwi¹¿ problem
                solveGame(&game);
                inGame = 0; // Oznacz koniec gry
                printf("Koniec gry\n");
            }
        } else { // Jeœli linia nie zawiera "Gra", analizuj informacje o grze
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
