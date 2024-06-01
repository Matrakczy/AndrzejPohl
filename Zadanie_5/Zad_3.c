#include <stdio.h>
#include <stdlib.h>

// Struktura w�z�a listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja tworz�ca nowy w�ze�
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("B��d alokacji pami�ci.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Funkcja dodaj�ca element na koniec listy
void push_back(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Funkcja usuwaj�ca ostatni element z listy
void remove_last(struct Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    } else if ((*head)->next == NULL) {
        // Je�li jest tylko jeden element w li�cie
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Funkcja wy�wietlaj�ca zawarto�� listy
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Dodajemy elementy do listy
    push_back(&head, 10);
    push_back(&head, 20);
    push_back(&head, 30);

    printf("Lista po dodaniu element�w: ");
    displayList(head);

    // Usuwamy ostatni element
    remove_last(&head);

    printf("Lista po usuni�ciu ostatniego elementu: ");
    displayList(head);

    return 0;
}
