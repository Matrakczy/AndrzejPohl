 #include <stdio.h>

// Deklaracje funkcji
double dodawanie(double a, double b) {
    return a + b;
}

double mnozenie(double a, double b) {
    return a * b;
}

double odejmowanie(double a, double b) {
    return a - b;
}

int main() {
    // Wskaünik do funkcji
    double (*wskaünik_do_funkcji)(double, double);

    // WybÛr operacji
    char operacja;
    printf("Wybierz operacjÍ:\n");
    printf("a) Dodawanie\n");
    printf("b) Mnoøenie\n");
    printf("c) Odejmowanie\n");
    scanf(" %c", &operacja);

    // Przypisanie wskaünika do odpowiedniej funkcji
    switch (operacja) {
        case 'a':
            wskaünik_do_funkcji = dodawanie;
            break;
        case 'b':
            wskaünik_do_funkcji = mnozenie;
            break;
        case 'c':
            wskaünik_do_funkcji = odejmowanie;
            break;
        default:
            printf("Nieprawid≥owy wybÛr operacji.\n");
            return 1;
    }

    // Wprowadzenie liczb
    double liczba1, liczba2;
    printf("Podaj dwie liczby: ");
    scanf("%lf %lf", &liczba1, &liczba2);

    // Wywo≥anie funkcji przez wskaünik i wyúwietlenie wyniku
    double wynik = wskaünik_do_funkcji(liczba1, liczba2);
    printf("Wynik: %.2lf\n", wynik);

    return 0;
}
