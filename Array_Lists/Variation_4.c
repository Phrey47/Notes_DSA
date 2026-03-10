// //Var 4
// #include <stdio.h>
// #include <stdlib.h>

// #define LENGTH 4  // Initial capacity

// typedef struct {
//     int *elem;   // dynamically allocated array
//     int count;   // current number of elements
//     int max;     // current capacity
// } List;

// // Function prototypes
// void initialize(List *L);
// void insertPos(List *L, int data, int position);
// void deletePos(List *L, int position);
// int locate(List *L, int data);
// int retrieve(List *L, int position);
// void insertSorted(List *L, int data);
// void display(List *L);
// void resize(List *L);
// void makeNULL(List *L);

// // Initialize the list
// void initialize(List *L) {
//     L->elem = (int *)malloc(LENGTH * sizeof(int));
//     L->max = LENGTH;
//     L->count = 0;
// }

// // Resize the list when full
// void resize(List *L) {
//     L->max *= 2;  
//     L->elem = (int *)realloc(L->elem, L->max * sizeof(int));
// }

// // Insert at specific position
// void insertPos(List *L, int data, int position) {
//     if (position < 0 || position > L->count) return;  // invalid pos
//     if (L->count == L->max) resize(L);  // resize if full

//     for (int i = L->count; i > position; i--) {
//         L->elem[i] = L->elem[i - 1];  // shift right
//     }

//     L->elem[position] = data;
//     L->count++;
// }

// // Delete from specific position
// void deletePos(List *L, int position) {
//     if (position < 0 || position >= L->count) return;  // invalid pos

//     for (int i = position; i < L->count - 1; i++) {
//         L->elem[i] = L->elem[i + 1];  // shift left
//     }

//     L->count--;
// }

// // Locate an element, return index or -1
// int locate(List *L, int data) {
//     for (int i = 0; i < L->count; i++) {
//         if (L->elem[i] == data) return i;
//     }
//     return -1;
// }

// // Retrieve element at position
// int retrieve(List *L, int position) {
//     if (position < 0 || position >= L->count) return -1; 
//     return L->elem[position];
// }

// // Insert while keeping array sorted
// void insertSorted(List *L, int data) {
//     if (L->count == L->max) resize(L);

//     int pos = 0;
//     while (pos < L->count && L->elem[pos] < data) {
//         pos++;
//     }

//     insertPos(L, data, pos);
// }

// // Display list elements
// void display(List *L) {
//     printf("List: ");
//     for (int i = 0; i < L->count; i++) {
//         printf("%d ", L->elem[i]);
//     }
//     printf("\n");
// }

// // Free memory
// void makeNULL(List *L) {
//     free(L->elem);
//     L->elem = NULL;
//     L->count = 0;
//     L->max = 0;
//     printf("List has been cleared.\n");
// }

// // Main function to test
// int main() {
//     List L;
//     initialize(&L);

//     insertPos(&L, 1, 0);
//     insertPos(&L, 2, 1);
//     insertPos(&L, 3, 2);
//     insertPos(&L, 4, 3);
//     display(&L);

//     insertPos(&L, 6, 9);
//     display(&L);

//     deletePos(&L, 1);
//     display(&L);

//     printf("Locate 5: %d\n", locate(&L, 5));
//     printf("Retrieve pos 2: %d\n", retrieve(&L, 2));

//     insertSorted(&L, 8);
//     display(&L);

//     makeNULL(&L);

//     return 0;
// }

//Variation 4 - Dynamic Array List with Person Struct and Memory Management
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 4

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct {
    Person *elem;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, Person data, int position);
void deletePos(List *L, int position);
int locate(List *L, int id);
Person retrieve(List *L, int position);
void insertSorted(List *L, Person data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

void initialize(List *L) {
    L->elem = (Person *)malloc(LENGTH * sizeof(Person));

    if (L->elem == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L) {
    Person *temp;
    L->max *= 2;
    temp = (Person *)realloc(L->elem, L->max * sizeof(Person));

    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
    }
    else {
        L->elem = temp;
        printf("List resized to capacity %d\n", L->max);
    }
}

void insertPos(List *L, Person data, int position) {
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
    }
    else {
        if (L->count == L->max) {
            resize(L);
        }
        for (int i = L->count; i > position && i < L->max; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position) {
    if (L->count == 0) {
        printf("List is empty!\n");
    }
    else if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
    }
    else {
        for (int i = position; i < L->count - 1 && i >= 0; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(List *L, int id) {
    int i = 0;
    int pos = -1;

    while (i < L->count && pos == -1) {
        if (L->elem[i].id == id) {
            pos = i;
        }
        i++;
    }
    return pos;
}

Person retrieve(List *L, int position) {
    Person temp;

    temp.id = -1;
    strcpy(temp.name, "INVALID");
    temp.age = -1;

    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
    }
    else {
        temp = L->elem[position];
    }
    return temp;
}

void insertSorted(List *L, Person data) {
    int pos = 0;

    if (L->count == L->max) {
        resize(L);
    }
    while (pos < L->count && L->elem[pos].id < data.id) {
        pos++;
    }
    insertPos(L, data, pos);
}

void display(List *L) {
    if (L->count == 0) {
        printf("List is empty!\n");
    }
    else {
        printf("\nList of Persons:\n");
        for (int i = 0; i < L->count && i < L->max; i++) {
            printf("ID:%d | Name:%s | Age:%d\n",
                   L->elem[i].id,
                   L->elem[i].name,
                   L->elem[i].age);
        }
    }
    printf("\n");
}

void makeNULL(List *L) {
    free(L->elem);
    L->elem = NULL;
    L->count = 0;
    L->max = 0;

    printf("List has been cleared.\n");
}

int main() {
    List L;
    Person p;
    Person temp;

    initialize(&L);

    p.id = 101; strcpy(p.name,"Alice"); p.age = 20;
    insertPos(&L, p, 0);

    p.id = 110; strcpy(p.name,"Bob"); p.age = 22;
    insertPos(&L, p, 1);

    p.id = 120; strcpy(p.name,"Charlie"); p.age = 21;
    insertPos(&L, p, 2);

    p.id = 130; strcpy(p.name,"David"); p.age = 23;
    insertPos(&L, p, 3);

    display(&L);

    printf("Deleting position 1...\n");
    deletePos(&L, 1);
    display(&L);

    printf("Insert Sorted...\n");

    p.id = 115; strcpy(p.name,"Eve"); p.age = 20;
    insertSorted(&L, p);

    display(&L);

    printf("Locate ID 115: %d\n", locate(&L,115));

    temp = retrieve(&L,2);

    if(temp.id != -1) {
        printf("Retrieved -> ID:%d Name:%s Age:%d\n",
               temp.id,temp.name,temp.age);
    }
    makeNULL(&L);

    return 0;
}