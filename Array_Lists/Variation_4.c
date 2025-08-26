#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

typedef struct {
    int id;
    char name[30];
} studtype;

typedef struct {
    studtype *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, studtype elem, int pos);
void deletePos(List *L, int pos);
void locate(List L, int ID);
studtype retrieve(List L, int pos);
void insertSorted(List *L, studtype elem);
void makeNULL(List *L);
void resize(List *L);
void display(List L);

void initialize(List *L) {
   
}

void resize(List *L) {
    
}

void insertPos(List *L, studtype elem, int pos) {
  
}

void deletePos(List *L, int pos) {
    
}

void locate(List L, int ID) {
    
}

studtype retrieve(List L, int pos) {
    
}

void insertSorted(List *L, studtype elem) {
    
}

void makeNULL(List *L) {
    
}

void display(List L) {
   
}

int main() {
    List L;
    initialize(&L);

    return 0;
}

