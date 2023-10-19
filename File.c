#include <stdio.h>
#include <stdlib.h>
// Define a structure for a singly linked list node.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node.
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list.
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}







// Function to insert a node at the end of the list.
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at the middle of the list.
struct Node* insertInMiddle(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node in the list.
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node in the middle of the list.
struct Node* deleteInMiddle(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    if (current->next == NULL) {
        return head;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to delete the last node in the list.
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to search for a value in the list.
int search(struct Node* head, int value) {
    int position = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Value not found.
}

// Function to print the linked list.
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning.
    head = insertAtBeginning(head, 10);
    printList(head);

    // Insert at the end.
    head = insertAtEnd(head, 20);
    printList(head);

    // Insert in the middle.
    head = insertInMiddle(head, 15, 1); // Insert 15 at position 1.
    printList(head);

    // Delete at the beginning.
    head = deleteAtBeginning(head);
    printList(head);

    // Delete in the middle.
    head = deleteInMiddle(head, 1); // Delete node at position 1.
    printList(head);

    // Delete at the end.
    head = deleteAtEnd(head);
    printList(head);

    // Search for a value.
    int position = search(head, 20);
    if (position != -1) {
        printf("Value 20 found at position %d.\n", position);
    } else {
        printf("Value 20 not found in the list.\n");
    }

    return 0;
}
