#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Funkcja do generowania losowego ruchu (papier, kamieñ lub no¿yce)
int generate_move() {
    return rand() % 3; // 0: kamieñ, 1: papier, 2: no¿yce
}

// Funkcja do okreœlania zwyciêzcy rundy
int determine_winner(int player_move, int computer_move) {
    if (player_move == computer_move) {
        return 0; // Remis
    } else if ((player_move == 0 && computer_move == 2) ||
               (player_move == 1 && computer_move == 0) ||
               (player_move == 2 && computer_move == 1)) {
        return 1; // Wygrywa gracz
    } else {
        return -1; // Wygrywa komputer
    }
}

int main() {
    int scores[3] = {0}; // Inicjalizacja wyników dla gracza, komputera i remisów
    char moves[3][10] = {"kamien", "papier", "nozyce"};
    char input[10];
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    printf("Witaj w grze Papier-Kamien-Nozyce!\n");

    while (1) {
        printf("\nWprowadz swoj ruch (kamien, papier lub nozyce): ");
        scanf("%s", input);

        int player_move;
        if (strcmp(input, "kamien") == 0) {
            player_move = 0;
        } else if (strcmp(input, "papier") == 0) {
            player_move = 1;
        } else if (strcmp(input, "nozyce") == 0) {
            player_move = 2;
        } else if (strcmp(input, "scores") == 0) {
            printf("Gracz: %d, Komputer: %d, Remisy: %d\n", scores[0], scores[1], scores[2]);
            continue;
        } else {
            printf("Nieprawidlowy ruch. Wprowadz kamien, papier lub nozyce.\n");
            continue;
        }

        int computer_move = generate_move();
        printf("Ruch komputera: %s\n", moves[computer_move]);

        int winner = determine_winner(player_move, computer_move);
        if (winner == 0) {
            printf("Remis!\n");
            scores[2]++;
        } else if (winner == 1) {
            printf("Wygrales!\n");
            scores[0]++;
        } else {
            printf("Komputer wygrywa!\n");
            scores[1]++;
        }
    }

    return 0;
}
