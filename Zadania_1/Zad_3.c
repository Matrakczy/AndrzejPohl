#include <stdio.h>
#include <conio.h>

// Funkcja obliczaj�ca silni�
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Funkcja drukuj�ca silni� dla ka�dej liczby w tablicy
void printFactorials(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        long long result = factorial(arr[i]);
        printf("Silnia z %d: %lld\n", arr[i], result);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    printFactorials(array, size);

    printf("Nacisnij dowolny klawisz, aby zakonczyc...\n");
    getch(); // Oczekiwanie na naci�ni�cie klawisza

    return 0;
}
