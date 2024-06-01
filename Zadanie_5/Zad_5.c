#include <stdio.h>
#include <stdlib.h>

// Struktura wêz³a listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania pierwszego elementu o danej wartoœci
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
            printf("Pierwszy element o wartoœci %d zosta³ usuniêty.\n", value);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Element o podanej wartoœci nie istnieje w liœcie.\n");
}

int main() {
    // Przyk³ad u¿ycia
    struct Node* list = NULL;

    // Dodajmy kilka elementów do listy
    for (int i = 0; i < 5; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = list;
        list = new_node;
    }

    // Wyœwietlmy listê przed usuniêciem
    printf("Lista przed usuniêciem:\n");
    struct Node* current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Usuñmy pierwszy element o wartoœci 3
    remove_first_by_value(&list, 3);

    // Wyœwietlmy zaktualizowan¹ listê
    printf("Lista po usuniêciu:\n");
    current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Zwolnijmy pamiêæ
    while (list != NULL) {
        current = list;
        list = list->next;
        free(current);
    }

    return 0;
}
