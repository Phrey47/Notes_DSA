#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

List initialize(List L) {
    L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
    if (L.elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List resize(List L) {
    int newSize = L.max * 2;
    int *newPtr = (int *)realloc(L.elemPtr, newSize * sizeof(int));
    // if (newPtr == NULL) {
    //     printf("Memory reallocation failed!\n");
    //     exit(1);
    // }
    L.elemPtr = newPtr;
    L.max = newSize;
    printf("List resized to capacity %d\n", L.max);
    return L;
}

// Insert an element at a specific position
List insertPos(List L, int data, int position) {
    if (L.count == L.max) {
        L = resize(L);
    }

    for (int i = L.count; i > position; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) {
    for (int i = position; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) {
            return i;
        }
    }
    return -1; 
}

List insertSorted(List L, int data) {
    if (L.count == L.max) {
        L = resize(L);
    }

    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data) {
        pos++;
    }
    L = insertPos(L, data, pos);
    return L;
}

void display(List L) {
    if (L.count == 0) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

int main() {
    List L;
    L = initialize(L);

    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 2);
    L = insertPos(L, 40, 3);
    L = insertPos(L, 50, 4);
    display(L); 

    L = deletePos(L, 2);
    display(L); 

    L = insertSorted(L, 60);
    // L = insertSorted(L, 5);
    L = insertSorted(L, 70);
    display(L);  
    int pos = locate(L, 60);
    if (pos != -1)
        printf("Element 60 found at position %d\n", pos);
    else
        printf("Element 60 not found!\n");

    free(L.elemPtr);
    return 0;
}

