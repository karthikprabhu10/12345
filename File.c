#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node at the middle of the list
void insertAtMiddle(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || position <= 1) {
        insertAtBeginning(head, data);
    } else {
        struct Node* current = *head;
        int count = 1;
        while (count < position - 1 && current->next != NULL) {
            current = current->next;
            count++;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Function to delete a node at the beginning of the list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

// Function to delete a node at the end of the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(current);
    }
}

// Function to delete a node at the middle of the list
void deleteAtMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* current = *head;
        int count = 1;
        while (count < position && current != NULL) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Position not found in the list.\n");
        } else {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
        }
    }
}

// Function to search for a specific value in the list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Key not found in the list
}

// Function to display the list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory and delete the entire list
void freeList(struct Node** head) {
    while (*head != NULL) {
        deleteAtBeginning(head);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key, result;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Middle\n");
        printf("7. Search for a Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtMiddle(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtMiddle(&head, position);
                break;
            case 7:
                printf("Enter the value to search for: ");
                scanf("%d", &key);
                result = search(head, key);
                if (result != -1) {
                    printf("%d found at position %d\n", key, result);
                } else {
                    printf("%d not found in the list\n", key);
                }
                break;
            case 8:
                display(head);
                break;
            case 9:
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


Circular Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at the middle of the circular linked list
void insertAtMiddle(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    while (count < position - 1 && current->next != *head) {
        current = current->next;
        count++;
    }

    if (count == position - 1) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Position exceeds the length of the list.\n");
    }
}

// Function to delete a node at the beginning of the circular linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    if (current == *head) {
        free(current);
        *head = NULL;
    } else {
        current->next = (*head)->next;
        free(*head);
        *head = current->next;
    }
}

// Function to delete a node at the end of the circular linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != *head) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        free(current);
        *head = NULL;
    } else {
        prev->next = *head;
        free(current);
    }
}

// Function to search for a specific value in the circular linked list
int search(struct Node* head, int key) {
    if (head == NULL) {
        return -1; // Key not found
    }

    struct Node* current = head;
    int position = 1;

    do {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != head);

    return -1; // Key not found
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(Head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key, result;

    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Search for a Value\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtMiddle(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the value to search for: ");
                scanf("%d", &key);
                result = search(head, key);
                if (result != -1) {
                    printf("%d found at position %d\n", key, result);
                } else {
                    printf("%d not found in the list\n", key);
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

