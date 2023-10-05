#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly circular linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to initialize an empty list
Node* initializeList() {
    return NULL;
}

// Function to insert an element at the beginning of the list
Node* insertAtBeginning(Node* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = list;
        newNode->prev = list->prev;
        list->prev->next = newNode;
        list->prev = newNode;
    }

    return newNode;
}

// Function to insert an element at the end of the list
Node* insertAtEnd(Node* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = list;
        newNode->prev = list->prev;
        list->prev->next = newNode;
        list->prev = newNode;
    }

    return list;
}

// Function to remove an element from the list based on a specific value
Node* removeElement(Node* list, int value) {
    if (list == NULL) {
        return NULL;
    }

    Node* current = list;
    do {
        if (current->data == value) {
            Node* nextNode = current->next;
            Node* prevNode = current->prev;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            if (current == list) {
                list = nextNode;
            }

            free(current);
            break;
        }

        current = current->next;
    } while (current != list);

    return list;
}

// Function to search for an element in the list
Node* searchElement(Node* list, int value) {
    Node* current = list;
    if (current == NULL) {
        return NULL;
    }

    do {
        if (current->data == value) {
            return current;
        }

        current = current->next;
    } while (current != list);

    return NULL;
}

// Function to display all elements of the list
void printList(Node* list) {
    Node* current = list;
    if (current == NULL) {
        printf("Empty list.\n");
        return;
    }

    printf("Current List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list);

    printf("\n");
}

int main() {
    Node* list = initializeList();
    int choice, value;

    do {
        printf("X------------------------------X\n");
        printf("| 1 - Insert at Beginning       |\n");
        printf("| 2 - Insert at End             |\n");
        printf("| 3 - Remove Element            |\n");
        printf("| 4 - Search Element            |\n");
        printf("| 5 - Display List              |\n");
        printf("| 6 - Exit                      |\n");
        printf("X------------------------------X\n");

        printf("Enter an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                list = insertAtBeginning(list, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                list = insertAtEnd(list, value);
                break;
            case 3:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                list = removeElement(list, value);
                break;
            case 4:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                Node* found = searchElement(list, value);
                if (found != NULL) {
                    printf("Value found in the list.\n");
                } else {
                    printf("Value not found in the list.\n");
                }
                break;
            case 5:
                printList(list);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    // Free allocated memory
    Node* current = list;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

