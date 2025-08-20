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

List locate(List L, int data){

}
List insertSorted(List L, int data){

}

void display(List L) {
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
    display(L);
    return 0;
}

