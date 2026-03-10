// // VARIATIONS 1
// #include <stdio.h>

// #define SIZE 10

// typedef struct {
//     int elem[SIZE];
//     int count;
// } List;

// List initialize(List L) {
//     L.count = 0;
//     return L;
// }

// List insertPos(List L, int data, int position) {
//     for (int i = L.count; i > position; i--) {
//         L.elem[i] = L.elem[i - 1];
//     }

//     L.elem[position] = data;
//     L.count++;
//     return L;
// }
// List deletePos(List L, int position){

//     for (int i = position; i < L.count - 1; i++) {
//         L.elem[i] = L.elem[i + 1];
//     }
//     L.count--;

//     return L;
// }

// int locate(List L, int data) {
//     for (int i = 0; i < L.count; i++) {
//         if (L.elem[i] == data) {
//             return i;
//         }
//     }
//     return -1;
// }

// List insertSorted(List L, int data) {
//     // if (L.count == MAX) {
//     //     printf("Error: List is full!\n");
//     //     return L;
//     // }

//     int pos = 0;
//     while (pos < L.count && L.elem[pos] < data) {
//         pos++;
//     }
//     L = insertPos(L, data, pos);
//     return L;
// }

// void display(List L) {
//     if (L.count == 0) {
//         printf("List is empty!\n");
//         return;
//     }

//     printf("List: ");
//     for (int i = 0; i < L.count; i++) {
//         printf("%d ", L.elem[i]);
//     }
//     printf("\n");
// }

// int main() {
//     List L;
//     L = initialize(L);

//     L = insertPos(L, 10, 0);
//     L = insertPos(L, 20, 1);
//     L = insertPos(L, 30, 2);
//     L = insertPos(L, 40, 3);
//     L = insertPos(L, 50, 4);
//     display(L);  

//     L = deletePos(L, 2);
//     display(L);  

//     L = insertSorted(L, 25);
//     //L = insertSorted(L, 5);
//     L = insertSorted(L, 35);
//     display(L);  

//     int pos = locate(L, 25);
//     if (pos != -1)
//         printf("Element 25 found at position %d\n", pos);
//     else
//         printf("Element 25 not found!\n");

//     return 0;
// }

// VARIATION 1 - ARRAY LIST USING PERSON STRUCTURE
#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct {
    Person elem[SIZE];
    int count;
} List;

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, Person data, int position) {
    int i;

    if (L.count >= SIZE) {
        printf("Error: List is full!\n");
    } 
    else if (position < 0 || position > L.count) {
        printf("Error: Invalid position!\n");
    } 
    else {
        for (i = L.count; i > position && i < SIZE; i--) {
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position) {
    int i;

    if (L.count == 0) {
        printf("Error: List is empty!\n");
    } 
    else if (position < 0 || position >= L.count) {
        printf("Error: Invalid position!\n");
    } 
    else {

        for (i = position; i < L.count - 1 && i >= 0; i++) {
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int id) {
    int i = 0;
    int pos = -1;

    while (i < L.count && pos == -1) {
        if (L.elem[i].id == id) {
            pos = i;
        }
        i++;
    }
    return pos;
}

List insertSorted(List L, Person data) {
    int pos = 0;

    if (L.count >= SIZE) {
        printf("Error: List is full!\n");
    } 
    else {
        while (pos < L.count && L.elem[pos].id < data.id) {
            pos++;
        }
        L = insertPos(L, data, pos);
    }
    return L;
}

void display(List L) {
    if (L.count == 0) {
        printf("List is empty!\n");
    } 
    else {
        printf("\nList of Persons:\n");

        for (int i = 0; i < L.count && i < SIZE; i++) {
            printf("ID: %d | Name: %s | Age: %d\n",
                   L.elem[i].id,
                   L.elem[i].name,
                   L.elem[i].age);
        }
    }
}

int main() {
    List L;
    Person p;

    L = initialize(L);


    p.id = 101; strcpy(p.name, "Alice"); p.age = 20;
    L = insertPos(L, p, 0);

    p.id = 105; strcpy(p.name, "Bob"); p.age = 22;
    L = insertPos(L, p, 1);

    p.id = 110; strcpy(p.name, "Charlie"); p.age = 21;
    L = insertPos(L, p, 2);

    p.id = 115; strcpy(p.name, "David"); p.age = 23;
    L = insertPos(L, p, 3);

    display(L);

    printf("\nDeleting position 2...\n");
    L = deletePos(L, 2);
    display(L);

    printf("\nInsert Sorted...\n");

    p.id = 108; strcpy(p.name, "Eve"); p.age = 20;
    L = insertSorted(L, p);

    p.id = 120; strcpy(p.name, "Frank"); p.age = 24;
    L = insertSorted(L, p);

    display(L);

    int pos = locate(L, 108);

    if (pos != -1)
        printf("\nPerson with ID 108 found at position %d\n", pos);
    else
        printf("\nPerson not found!\n");

    return 0;
}

