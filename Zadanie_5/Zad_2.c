#include <stdio.h>
#include <stdlib.h>

// Struktura wêz³a listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja tworz¹ca nowy wêze³
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("B³¹d alokacji pamiêci.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Funkcja dodaj¹ca element na koniec listy
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

// Funkcja wyœwietlaj¹ca zawartoœæ listy
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

    printf("Lista po dodaniu elementow: ");
    displayList(head);

    // Usuwamy pierwszy element
    if (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    printf("Lista po usunieciu pierwszego elementu: ");
    displayList(head);

    return 0;
}
