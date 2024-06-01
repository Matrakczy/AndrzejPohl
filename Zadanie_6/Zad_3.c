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
    // Wska�nik do funkcji
    double (*wska�nik_do_funkcji)(double, double);

    // Wyb�r operacji
    char operacja;
    printf("Wybierz operacj�:\n");
    printf("a) Dodawanie\n");
    printf("b) Mno�enie\n");
    printf("c) Odejmowanie\n");
    scanf(" %c", &operacja);

    // Przypisanie wska�nika do odpowiedniej funkcji
    switch (operacja) {
        case 'a':
            wska�nik_do_funkcji = dodawanie;
            break;
        case 'b':
            wska�nik_do_funkcji = mnozenie;
            break;
        case 'c':
            wska�nik_do_funkcji = odejmowanie;
            break;
        default:
            printf("Nieprawid�owy wyb�r operacji.\n");
            return 1;
    }

    // Wprowadzenie liczb
    double liczba1, liczba2;
    printf("Podaj dwie liczby: ");
    scanf("%lf %lf", &liczba1, &liczba2);

    // Wywo�anie funkcji przez wska�nik i wy�wietlenie wyniku
    double wynik = wska�nik_do_funkcji(liczba1, liczba2);
    printf("Wynik: %.2lf\n", wynik);

    return 0;
}
