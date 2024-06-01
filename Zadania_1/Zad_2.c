#include <stdio.h>
#include <conio.h>
int main() {
    const int num_students = 5;
    const int num_subjects = 2;

    // Dwuwymiarowa tablica ocen
    int grades[num_subjects][num_students];

    // Wczytaj oceny od u¿ytkownika
    for (int subject = 0; subject < num_subjects; ++subject) {
        printf("Oceny z przedmiotu %s:\n", subject == 0 ? "matematyki" : "fizyki");
        for (int student = 0; student < num_students; ++student) {
            printf("Uczeñ %d: ", student + 1);
            scanf("%d", &grades[subject][student]);
        }
    }

    // Oblicz œredni¹ ocen
    double average_math = 0.0;
    double average_physics = 0.0;

    for (int student = 0; student < num_students; ++student) {
        average_math += grades[0][student];
        average_physics += grades[1][student];
    }

    average_math /= num_students;
    average_physics /= num_students;

    // Wyœwietl wyniki
    printf("Srednia ocen z matematyki: %.2lf\n", average_math);
    printf("Srednia ocen z fizyki: %.2lf\n", average_physics);

    // Oczekuj na naciœniêcie dowolnego klawisza przed zakoñczeniem programu
    printf("Nacisnij dowolny klawisz, aby zakonczyc...");
    _getch(); //oczekiwanie na naciœniêcie klawisza

    return 0;
}
