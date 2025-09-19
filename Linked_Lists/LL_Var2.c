#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// List structure
typedef struct {
    Node *head;
    int count;
} List;

// Function prototypes
List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

// Initialize a new list
List* initialize() {
    List *list = (List*)malloc(sizeof(List));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->count = 0;
    return list;
}

// Free all nodes
void empty(List *list) {
    Node *current = list->head;
    Node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

// Insert at beginning
void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

// Insert at end
void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

// Insert at position
void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) return;

    if (index == 0) {
        insertFirst(list, data);
    } else if (index == list->count) {
        insertLast(list, data);
    } else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;

        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

// Delete from start
void deleteStart(List *list) {
    if (list->head == NULL) return;

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

// Delete last node
void deleteLast(List *list) {
    if (list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

// Delete at position
void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) return;

    if (index == 0) {
        deleteStart(list);
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->count--;
    }
}

// Retrieve data at index
int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) return -1;

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Locate index of data
int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) return index;
        current = current->next;
        index++;
    }
    return -1;
}

// Display list contents
void display(List *list) {
    Node *current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL (count=%d)\n", list->count);
}

// Main function to test
int main() {
    List *list = initialize();

    insertFirst(list, 5);
    insertFirst(list, 6);
    insertFirst(list, 2);
    display(list);  // 2 -> 6 -> 5

    insertLast(list, 7);
    display(list);  // 2 -> 6 -> 5 -> 7

    insertPos(list, 9, 2);
    display(list);  // 2 -> 6 -> 9 -> 5 -> 7

    deleteStart(list);
    display(list);  // 6 -> 9 -> 5 -> 7

    deleteLast(list);
    display(list);  // 6 -> 9 -> 5

    deletePos(list, 1);
    display(list);  // 6 -> 5

    printf("Retrieve index 1: %d\n", retrieve(list, 1));
    printf("Locate data 6: %d\n", locate(list, 6));

    empty(list);
    display(list);

    free(list);
    return 0;
}
