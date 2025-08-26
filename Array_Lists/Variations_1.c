#include <stdio.h>

#define SIZE 10

typedef struct {
    int elem[SIZE];
    int count;
} List;

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;
    L.count++;
    return L;
}
List deletePos(List L, int position){

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    // if (L.count == MAX) {
    //     printf("Error: List is full!\n");
    //     return L;
    // }

    int pos = 0;
    while (pos < L.count && L.elem[pos] < data) {
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
        printf("%d ", L.elem[i]);
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

    L = insertSorted(L, 25);
    //L = insertSorted(L, 5);
    L = insertSorted(L, 35);
    display(L);  

    int pos = locate(L, 25);
    if (pos != -1)
        printf("Element 25 found at position %d\n", pos);
    else
        printf("Element 25 not found!\n");

    return 0;
}


