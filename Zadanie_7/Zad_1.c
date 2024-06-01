#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Funkcja do obliczania wartoœci energetycznej
int calculateEnergyValue(const char *line) {
    int sum = 0;
    int firstDigit = -1;
    int lastDigit = -1;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            if (firstDigit == -1) {
                firstDigit = line[i] - '0';
            } else {
                lastDigit = line[i] - '0';
                break;
            }
        }
    }

    if (firstDigit != -1 && lastDigit != -1) {
        sum = firstDigit + lastDigit;
    }

    return sum;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Nie mo¿na otworzyæ pliku input.txt.\n");
        return 1;
    }

    int totalEnergy = 0;
    char line[100]; // Za³ó¿my, ¿e linie nie przekrocz¹ 100 znaków

    while (fgets(line, sizeof(line), file)) {
        totalEnergy += calculateEnergyValue(line);
    }

    fclose(file);

    printf("Suma wartoœci energetycznych: %d\n", totalEnergy);

    return 0;
}
