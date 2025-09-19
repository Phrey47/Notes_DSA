#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4  // Initial capacity

typedef struct {
    int *elem;   // dynamically allocated array
    int count;   // current number of elements
    int max;     // current capacity
} List;

// Function prototypes
void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

// Initialize the list
void initialize(List *L) {
    L->elem = (int *)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

// Resize the list when full
void resize(List *L) {
    L->max *= 2;  
    L->elem = (int *)realloc(L->elem, L->max * sizeof(int));
}

// Insert at specific position
void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) return;  // invalid pos
    if (L->count == L->max) resize(L);  // resize if full

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];  // shift right
    }

    L->elem[position] = data;
    L->count++;
}

// Delete from specific position
void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) return;  // invalid pos

    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];  // shift left
    }

    L->count--;
}

// Locate an element, return index or -1
int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) return i;
    }
    return -1;
}

// Retrieve element at position
int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) return -1; 
    return L->elem[position];
}

// Insert while keeping array sorted
void insertSorted(List *L, int data) {
    if (L->count == L->max) resize(L);

    int pos = 0;
    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }

    insertPos(L, data, pos);
}

// Display list elements
void display(List *L) {
    printf("List: ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

// Free memory
void makeNULL(List *L) {
    free(L->elem);
    L->elem = NULL;
    L->count = 0;
    L->max = 0;
    printf("List has been cleared.\n");
}

// Main function to test
int main() {
    List L;
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 2, 1);
    insertPos(&L, 3, 2);
    insertPos(&L, 4, 3);
    display(&L);

    insertPos(&L, 6, 9);
    display(&L);

    deletePos(&L, 1);
    display(&L);

    printf("Locate 5: %d\n", locate(&L, 5));
    printf("Retrieve pos 2: %d\n", retrieve(&L, 2));

    insertSorted(&L, 8);
    display(&L);

    makeNULL(&L);

    return 0;
}
