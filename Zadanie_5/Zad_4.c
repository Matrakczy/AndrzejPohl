#include <stdio.h>
#include <stdlib.h>

// Struktura wêz³a listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania elementu na podstawie indeksu
void remove_by_index(struct Node** head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    if (index < 0) {
        printf("Nieprawid³owy indeks.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    // Przesuwamy siê do wêz³a o indeksie (index - 1)
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            printf("Indeks przekracza rozmiar listy.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    // Usuwamy wêze³ o indeksie index
    if (previous == NULL) {
        // Usuwanie pierwszego elementu
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Element o indeksie %d zosta³ usuniêty.\n", index);
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

    // Usuñmy element o indeksie 2
    remove_by_index(&list, 2);

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
