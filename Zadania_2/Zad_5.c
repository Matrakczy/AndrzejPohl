#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Definicja struktury Contact przechowuj¹cej imiê, nazwisko i numer telefonu
struct Contact {
    char imie[50];
    char nazwisko[50];
    char numer_telefonu[15];
};

// Struktura przechowuj¹ca ksi¹¿kê adresow¹
struct AddressBook {
    struct Contact kontakty[MAX_CONTACTS];
    int liczba_kontaktow;
};

// Funkcja dodaj¹ca nowy kontakt do ksi¹¿ki adresowej
void dodajKontakt(struct AddressBook *ksiazka, const char *imie, const char *nazwisko, const char *numer_telefonu) {
    if (ksiazka->liczba_kontaktow < MAX_CONTACTS) {
        struct Contact nowy_kontakt;
        strcpy(nowy_kontakt.imie, imie);
        strcpy(nowy_kontakt.nazwisko, nazwisko);
        strcpy(nowy_kontakt.numer_telefonu, numer_telefonu);

        ksiazka->kontakty[ksiazka->liczba_kontaktow] = nowy_kontakt;
        ksiazka->liczba_kontaktow++;
        printf("Dodano nowy kontakt.\n");
    } else {
        printf("Ksiazka adresowa jest pelna.\n");
    }
}

// Funkcja wyszukuj¹ca kontakt po nazwisku
void znajdzKontakt(const struct AddressBook *ksiazka, const char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < ksiazka->liczba_kontaktow; ++i) {
        if (strcmp(ksiazka->kontakty[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka->kontakty[i].imie);
            printf("Nazwisko: %s\n", ksiazka->kontakty[i].nazwisko);
            printf("Numer telefonu: %s\n", ksiazka->kontakty[i].numer_telefonu);
            znaleziono = 1;
        }
    }
    if (!znaleziono) {
        printf("Kontakt o nazwisku '%s' nie zostal znaleziony.\n", nazwisko);
    }
}

// Funkcja usuwaj¹ca kontakt po nazwisku
void usunKontakt(struct AddressBook *ksiazka, const char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < ksiazka->liczba_kontaktow; ++i) {
        if (strcmp(ksiazka->kontakty[i].nazwisko, nazwisko) == 0) {
            for (int j = i; j < ksiazka->liczba_kontaktow - 1; ++j) {
                ksiazka->kontakty[j] = ksiazka->kontakty[j + 1];
            }
            ksiazka->liczba_kontaktow--;
            printf("Kontakt o nazwisku '%s' zostal usuniety.\n", nazwisko);
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) {
        printf("Kontakt o nazwisku '%s' nie zostal znaleziony.\n", nazwisko);
    }
}

// Funkcja wypisuj¹ca wszystkie kontakty w ksi¹¿ce adresowej
void wypiszWszystkieKontakty(const struct AddressBook *ksiazka) {
    printf("Wszystkie kontakty w ksiazce adresowej:\n");
    for (int i = 0; i < ksiazka->liczba_kontaktow; ++i) {
        printf("Imie: %s, Nazwisko: %s, Numer telefonu: %s\n", ksiazka->kontakty[i].imie,
               ksiazka->kontakty[i].nazwisko, ksiazka->kontakty[i].numer_telefonu);
    }
}

int main() {
    struct AddressBook ksiazka_adresowa = {0};

    // Prosty interfejs u¿ytkownika
    char opcja;
    do {
        printf("\nWybierz opcje:\n");
        printf("1. Dodaj nowy kontakt\n");
        printf("2. Znajdz kontakt po nazwisku\n");
        printf("3. Usun kontakt po nazwisku\n");
        printf("4. Wypisz wszystkie kontakty\n");
        printf("5. Zakoncz program\n");
        printf("Opcja: ");
        scanf(" %c", &opcja);

        switch (opcja) {
            case '1': {
                char imie[50], nazwisko[50], numer_telefonu[15];
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", numer_telefonu);
                dodajKontakt(&ksiazka_adresowa, imie, nazwisko, numer_telefonu);
                break;
            }
            case '2': {
                char nazwisko[50];
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", nazwisko);
                znajdzKontakt(&ksiazka_adresowa, nazwisko);
                break;
            }
            case '3': {
                char nazwisko[50];
                printf("Podaj nazwisko do usuniecia: ");
                scanf("%s", nazwisko);
                usunKontakt(&ksiazka_adresowa, nazwisko);
                break;
            }
            case '4':
                wypiszWszystkieKontakty(&ksiazka_adresowa);
                break;
            case '5':
                printf("Koniec programu.\n");
                break;
            default:
                printf("Niepoprawna opcja.\n");
        }
    } while (opcja != '5');

    return 0;
}
