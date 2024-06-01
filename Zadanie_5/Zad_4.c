#include <stdio.h>
#include <stdlib.h>

// Struktura w�z�a listy
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
        printf("Nieprawid�owy indeks.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    // Przesuwamy si� do w�z�a o indeksie (index - 1)
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            printf("Indeks przekracza rozmiar listy.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    // Usuwamy w�ze� o indeksie index
    if (previous == NULL) {
        // Usuwanie pierwszego elementu
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Element o indeksie %d zosta� usuni�ty.\n", index);
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

    // Usu�my element o indeksie 2
    remove_by_index(&list, 2);

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
