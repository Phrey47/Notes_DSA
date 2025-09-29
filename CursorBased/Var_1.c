#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeadSpace[MAX];

typedef struct {
    HeadSpace heap;
    int avail;
} VHeap;

//typedef int List;

void initialize(VHeap *V) {
    for (int i = 0; i < MAX - 1; i++){  
        V->heap[i].next = i + 1;
    }
    V->heap[MAX - 1].next = -1;  
    V->avail = 0;                
}

int allocSpace(VHeap *V){
    int index = V->avail;
    if(index != -1){
        V->avail  = V->heap[index].next;
    }
    return index;
}
void deallocSpace(VHeap *V, int index){
    V->heap[index].next = V->avail;
    V->avail = index;
}
void insertFirst(int *L, VHeap *V, int elem){
    int newCell = allocSpace(V);

    if(newCell != -1){
        V->heap[newCell].elem = elem;
        V->heap[newCell].next = *L;
    }
    *L = newCell;
}
void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->heap[newCell].elem = elem;
        V->heap[newCell].next = -1;
        int *trav = L;

        while(*trav != -1){
            trav = &V->heap[*trav].next;
        }
        *trav = newCell;
    } 
}
void insertSorted(int* L, VHeap* V, int elem){

}
void delete(int* L, VHeap* V, int elem){

}
void deleteAllOccurrence(int* L, VHeap* V, int elem){

}
void display(int L, VHeap V){
    int trav = L;
    while(trav != -1){
        printf("%d -> ", V.heap[trav].elem);
            trav = V.heap[trav].next;
        }
    }

int main(){
    VHeap vh;
    initialize(&vh);
    int list = -1;

    insertFirst(&list, &vh, 10);
    insertFirst(&list, &vh, 20);
    insertLast(&list, &vh, 5);

    printf("List: ");
    display(list, vh); 
}