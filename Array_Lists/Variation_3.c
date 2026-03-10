// //VAR 3
// #include <stdio.h>
// #include <stdlib.h>
// #define LENGTH 10

// typedef struct {
//     int *elemPtr;
//     int count;
//     int max;
// } List;

// List initialize(List L);
// List insertPos(List L, int data, int position);
// List deletePos(List L, int position);
// int locate(List L, int data);
// List insertSorted(List L, int data);
// void display(List L);
// List resize(List L);

// List initialize(List L) {
//     L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
//     if (L.elemPtr == NULL) {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }
//     L.count = 0;
//     L.max = LENGTH;
//     return L;
// }

// List resize(List L) {
//     int newSize = L.max * 2;
//     int *newPtr = (int *)realloc(L.elemPtr, newSize * sizeof(int));
//     // if (newPtr == NULL) {
//     //     printf("Memory reallocation failed!\n");
//     //     exit(1);
//     // }
//     L.elemPtr = newPtr;
//     L.max = newSize;
//     printf("List resized to capacity %d\n", L.max);
//     return L;
// }

// // Insert an element at a specific position
// List insertPos(List L, int data, int position) {
//     if (L.count == L.max) {
//         L = resize(L);
//     }

//     for (int i = L.count; i > position; i--) {
//         L.elemPtr[i] = L.elemPtr[i - 1];
//     }

//     L.elemPtr[position] = data;
//     L.count++;
//     return L;
// }

// List deletePos(List L, int position) {
//     for (int i = position; i < L.count - 1; i++) {
//         L.elemPtr[i] = L.elemPtr[i + 1];
//     }

//     L.count--;
//     return L;
// }

// int locate(List L, int data) {
//     for (int i = 0; i < L.count; i++) {
//         if (L.elemPtr[i] == data) {
//             return i;
//         }
//     }
//     return -1; 
// }

// List insertSorted(List L, int data) {
//     if (L.count == L.max) {
//         L = resize(L);
//     }

//     int pos = 0;
//     while (pos < L.count && L.elemPtr[pos] < data) {
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
//         printf("%d ", L.elemPtr[i]);
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

//     L = insertSorted(L, 60);
//     // L = insertSorted(L, 5);
//     L = insertSorted(L, 70);
//     display(L);  
//     int pos = locate(L, 60);
//     if (pos != -1)
//         printf("Element 60 found at position %d\n", pos);
//     else
//         printf("Element 60 not found!\n");

//     free(L.elemPtr);
//     return 0;
// }

//Variation 3 - Dynamic Array List with Person Struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct {
    Person *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List resize(List L);
List insertPos(List L, Person data, int position);
List deletePos(List L, int position);
int locate(List L, int id);
List insertSorted(List L, Person data);
void display(List L);


List initialize(List L) {

    L.elemPtr = (Person *)malloc(LENGTH * sizeof(Person));

    if (L.elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    L.count = 0;
    L.max = LENGTH;

    return L;
}

List insertPos(List L, Person data, int position) {

    if (position < 0 || position > L.count) {
        printf("Invalid position!\n");
    }
    else {
        if (L.count == L.max) {
            L = resize(L);
        }
        for (int i = L.count; i > position && i < L.max; i--) {
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position) {

    if (L.count == 0) {
        printf("List is empty!\n");
    }
    else if (position < 0 || position >= L.count) {
        printf("Invalid position!\n");
    }
    else {
        for (int i = position; i < L.count - 1 && i >= 0; i++) {
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int id) {
    int i = 0;
    int pos = -1;

    while (i < L.count && pos == -1) {
        if (L.elemPtr[i].id == id) {
            pos = i;
        }
        i++;
    }
    return pos;
}

List insertSorted(List L, Person data) {
    int pos = 0;

    if (L.count == L.max) {
        L = resize(L);
    }
    while (pos < L.count && L.elemPtr[pos].id < data.id) {
        pos++;
    }

    L = insertPos(L, data, pos);
    return L;
}

List resize(List L) {

    Person *newPtr;
    int newSize = L.max * 2;

    newPtr = (Person *)realloc(L.elemPtr, newSize * sizeof(Person));

    if (newPtr == NULL) {
        printf("Memory reallocation failed!\n");
    }
    else {
        L.elemPtr = newPtr;
        L.max = newSize;
        printf("List resized to capacity %d\n", L.max);
    }
    return L;
}

void display(List L) {
    if (L.count == 0) {
        printf("List is empty!\n");
    }
    else {
        printf("\nList of Persons:\n");
        for (int i = 0; i < L.count && i < L.max; i++) {
            printf("ID: %d | Name: %s | Age: %d\n",
                   L.elemPtr[i].id,
                   L.elemPtr[i].name,
                   L.elemPtr[i].age);
        }
    }
}

int main() {
    List L;
    Person p;

    L = initialize(L);

    p.id = 101; strcpy(p.name, "Alice"); p.age = 20;
    L = insertPos(L, p, 0);

    p.id = 110; strcpy(p.name, "Bob"); p.age = 22;
    L = insertPos(L, p, 1);

    p.id = 120; strcpy(p.name, "Charlie"); p.age = 21;
    L = insertPos(L, p, 2);

    p.id = 130; strcpy(p.name, "David"); p.age = 23;
    L = insertPos(L, p, 3);

    p.id = 140; strcpy(p.name, "Eve"); p.age = 20;
    L = insertPos(L, p, 4);

    display(L);

    printf("\nDeleting position 2...\n");
    L = deletePos(L, 2);
    display(L);

    printf("\nInsert Sorted...\n");

    p.id = 125; strcpy(p.name, "Frank"); p.age = 24;
    L = insertSorted(L, p);

    p.id = 150; strcpy(p.name, "Grace"); p.age = 22;
    L = insertSorted(L, p);

    display(L);

    int pos = locate(L, 125);

    if (pos != -1)
        printf("\nPerson with ID 125 found at position %d\n", pos);
    else
        printf("\nPerson not found!\n");

    free(L.elemPtr);
    return 0;
}