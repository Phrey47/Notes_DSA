#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void makeNULL(EPtr L);
void display(EPtr L);

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    // if (L->count == MAX) {
    //     printf("List is full!\n");
    //     return;
    // }
    // if (position < 0 || position > L->count) {
    //     printf("Invalid position!\n");
    //     return;
    // }
    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position) {
    // if (L->count == 0) {
    //     printf("List is empty!\n");
    //     return;
    // }
    // if (position < 0 || position >= L->count) {
    //     printf("Invalid position!\n");
    //     return;
    // }
    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i;
        }
    }
    return -1; 
}

int retrieve(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data) {
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }
    int pos = 0;
    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }
    insertPos(L, data, pos);
}

void makeNULL(EPtr L) {
    L->count = 0;
}

void display(EPtr L) {
    printf("List: ");
        for (int i = 0; i < L->count; i++) {
            printf("%d ", L->elem[i]);
        }
        printf("\n");
    }

int main() {
    Etype list;
    EPtr L = &list;

    initialize(L);
    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 30, 2);
    display(L); 

    deletePos(L, 1);
    display(L); 

    insertSorted(L, 15);
    insertSorted(L, 5);
    insertSorted(L, 25);
    display(L); 

    int pos = locate(L, 15);
    if (pos != -1)
        printf("Element 15 found at position %d\n", pos);
    else
        printf("Element 15 not found!\n");

    printf("Element at position 2: %d\n", retrieve(L, 2));

    makeNULL(L);
    display(L);  

    return 0;
}
