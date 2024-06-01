#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentuj¹ca element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja dodaj¹ca element na pocz¹tek listy
struct Node* addFirst(struct Node* head, int value) {
    // Tworzymy nowy element
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    // Ustawiamy nowy element jako nag³ówek listy
    head = newNode;

    return head;
}

// Funkcja wyœwietlaj¹ca listê
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Dodajemy elementy na pocz¹tek listy
    head = addFirst(head, 10);
    head = addFirst(head, 20);
    head = addFirst(head, 30);

    // Wyœwietlamy listê
    printf("Lista: ");
    displayList(head);

    return 0;
}
