// //VAR 2
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 10

// typedef struct {
//     int elem[MAX];
//     int count;
// } Etype, *EPtr;

// void initialize(EPtr L);
// void insertPos(EPtr L, int data, int position);
// void deletePos(EPtr L, int position);
// int locate(EPtr L, int data);
// int retrieve(EPtr L, int position);
// void insertSorted(EPtr L, int data);
// void makeNULL(EPtr L);
// void display(EPtr L);

// void initialize(EPtr L) {
//     L->count = 0;
// }

// void insertPos(EPtr L, int data, int position) {
//     // if (L->count == MAX) {
//     //     printf("List is full!\n");
//     //     return;
//     // }
//     // if (position < 0 || position > L->count) {
//     //     printf("Invalid position!\n");
//     //     return;
//     // }
//     for (int i = L->count; i > position; i--) {
//         L->elem[i] = L->elem[i - 1];
//     }
//     L->elem[position] = data;
//     L->count++;
// }

// void deletePos(EPtr L, int position) {
//     // if (L->count == 0) {
//     //     printf("List is empty!\n");
//     //     return;
//     // }
//     // if (position < 0 || position >= L->count) {
//     //     printf("Invalid position!\n");
//     //     return;
//     // }
//     for (int i = position; i < L->count - 1; i++) {
//         L->elem[i] = L->elem[i + 1];
//     }
//     L->count--;
// }

// int locate(EPtr L, int data) {
//     for (int i = 0; i < L->count; i++) {
//         if (L->elem[i] == data) {
//             return i;
//         }
//     }
//     return -1; 
// }

// int retrieve(EPtr L, int position) {
//     if (position < 0 || position >= L->count) {
//         printf("Invalid position!\n");
//         return -1;
//     }
//     return L->elem[position];
// }

// void insertSorted(EPtr L, int data) {
//     if (L->count == MAX) {
//         printf("List is full!\n");
//         return;
//     }
//     int pos = 0;
//     while (pos < L->count && L->elem[pos] < data) {
//         pos++;
//     }
//     insertPos(L, data, pos);
// }

// void makeNULL(EPtr L) {
//     L->count = 0;
// }

// void display(EPtr L) {
//     printf("List: ");
//         for (int i = 0; i < L->count; i++) {
//             printf("%d ", L->elem[i]);
//         }
//         printf("\n");
//     }

// int main() {
//     Etype list;
//     EPtr L = &list;

//     initialize(L);
//     insertPos(L, 10, 0);
//     insertPos(L, 20, 1);
//     insertPos(L, 30, 2);
//     display(L); 

//     deletePos(L, 1);
//     display(L); 

//     insertSorted(L, 15);
//     insertSorted(L, 5);
//     insertSorted(L, 25);
//     display(L); 

//     int pos = locate(L, 15);
//     if (pos != -1)
//         printf("Element 15 found at position %d\n", pos);
//     else
//         printf("Element 15 not found!\n");

//     printf("Element at position 2: %d\n", retrieve(L, 2));

//     makeNULL(L);
//     display(L);  

//     return 0;
// }

// VARIATION 2 - ARRAY LIST WITH PERSON STRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct {
    Person elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, Person data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int id);
Person retrieve(EPtr L, int position);
void insertSorted(EPtr L, Person data);
void makeNULL(EPtr L);
void display(EPtr L);


void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, Person data, int position) {
    if (L->count >= MAX) {
        printf("Error: List is full!\n");
    }
    else if (position < 0 || position > L->count) {
        printf("Error: Invalid position!\n");
    }
    else {
        for (int i = L->count; i > position && i < MAX; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position) {
    int i;

    if (L->count == 0) {
        printf("Error: List is empty!\n");
    }
    else if (position < 0 || position >= L->count) {
        printf("Error: Invalid position!\n");
    }
    else {
        for (i = position; i < L->count - 1 && i >= 0; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(EPtr L, int id) {
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

Person retrieve(EPtr L, int position) {
    Person temp;

    temp.id = -1;
    strcpy(temp.name, "INVALID");
    temp.age = -1;

    if (position < 0 || position >= L->count) {
        printf("Error: Invalid position!\n");
    }
    else {
        temp = L->elem[position];
    }
    return temp;
}

void insertSorted(EPtr L, Person data) {
    int pos = 0;

    if (L->count >= MAX) {
        printf("Error: List is full!\n");
    }
    else {
        while (pos < L->count && L->elem[pos].id < data.id) {
            pos++;
        }
        insertPos(L, data, pos);
    }
}

void makeNULL(EPtr L) {
    L->count = 0;
}

void display(EPtr L) {
    int i;

    if (L->count == 0) {
        printf("List is empty!\n");
    }
    else {
        printf("\nList of Persons:\n");

        for (i = 0; i < L->count && i < MAX; i++) {
            printf("ID: %d | Name: %s | Age: %d\n",
                   L->elem[i].id,
                   L->elem[i].name,
                   L->elem[i].age);
        }
    }
    printf("\n");
}

int main() {
    Etype list;
    EPtr L = &list;

    Person p;
    Person temp;

    initialize(L);

    p.id = 101; strcpy(p.name, "Alice"); p.age = 20;
    insertPos(L, p, 0);

    p.id = 110; strcpy(p.name, "Bob"); p.age = 21;
    insertPos(L, p, 1);

    p.id = 120; strcpy(p.name, "Charlie"); p.age = 22;
    insertPos(L, p, 2);

    display(L);

    printf("Deleting position 1...\n");
    deletePos(L, 1);
    display(L);

    printf("Insert Sorted...\n");

    p.id = 115; strcpy(p.name, "David"); p.age = 23;
    insertSorted(L, p);

    p.id = 105; strcpy(p.name, "Eve"); p.age = 20;
    insertSorted(L, p);

    p.id = 130; strcpy(p.name, "Frank"); p.age = 24;
    insertSorted(L, p);

    display(L);

    int pos = locate(L, 115);

    if (pos != -1)
        printf("Person with ID 115 found at position %d\n", pos);
    else
        printf("Person not found!\n");

    temp = retrieve(L, 2);

    if (temp.id != -1) {
        printf("Retrieved Person -> ID:%d Name:%s Age:%d\n",
               temp.id, temp.name, temp.age);
    }

    printf("\nMaking list NULL...\n");
    makeNULL(L);
    display(L);

    return 0;
}