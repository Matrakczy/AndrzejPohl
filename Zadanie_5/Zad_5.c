#include <stdio.h>
#include <stdlib.h>

// Struktura w�z�a listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania pierwszego elementu o danej warto�ci
void remove_first_by_value(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                // Usuwanie pierwszego elementu
                *head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            printf("Pierwszy element o warto�ci %d zosta� usuni�ty.\n", value);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Element o podanej warto�ci nie istnieje w li�cie.\n");
}

int main() {
    // Przyk�ad u�ycia
    struct Node* list = NULL;

    // Dodajmy kilka element�w do listy
    for (int i = 0; i < 5; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = list;
        list = new_node;
    }

    // Wy�wietlmy list� przed usuni�ciem
    printf("Lista przed usuni�ciem:\n");
    struct Node* current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Usu�my pierwszy element o warto�ci 3
    remove_first_by_value(&list, 3);

    // Wy�wietlmy zaktualizowan� list�
    printf("Lista po usuni�ciu:\n");
    current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Zwolnijmy pami��
    while (list != NULL) {
        current = list;
        list = list->next;
        free(current);
    }

    return 0;
}
