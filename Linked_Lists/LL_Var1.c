//Variant 1: Basic linked list operations with Person struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List initialize(List L);
List empty(List L);
List insertFirst(List L, Person data);
List insertLast(List L, Person data);
List insertPos(List L, Person data, int index);
List deleteStart(List L);
List deleteLast(List L);
List deletePos(List L, int index);
Person retrieve(List L, int index);
int locate(List L, int id);
void display(List L);

List initialize(List L) {
    L.head = NULL;
    L.count = 0;

    return L;
}

List empty(List L) {
    Node *current = L.head;
    Node *temp;

    while (current != NULL && L.count >= 0) {
        temp = current;
        current = current->next;

        free(temp);
    }
    L.head = NULL;
    L.count = 0;

    return L;
}

List insertFirst(List L, Person data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    } else {
        newNode->data = data;
        newNode->next = L.head;

        L.head = newNode;
        L.count++;
    }
    return L;
}

List insertLast(List L, Person data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *current;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");

    } else {
        newNode->data = data;
        newNode->next = NULL;
        if (L.head == NULL) {
            L.head = newNode;
        } else {
            current = L.head;
            while (current->next != NULL && L.count >= 0) {
                current = current->next;
            }
            current->next = newNode;
        }
        L.count++;
    }
    return L;
}

List insertPos(List L, Person data, int index) {
    Node *newNode;
    Node *current;

    if (index < 0 || index > L.count) {
        printf("Invalid position!\n");
    } else if (index == 0) {
        L = insertFirst(L, data);
    } else if (index == L.count) {
        L = insertLast(L, data);
    } else {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
        } else {
            newNode->data = data;
            current = L.head;

            for (int i = 0; i < index - 1 && current != NULL; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
           
            L.count++;
        }
    }
    return L;
}

List deleteStart(List L) {
    Node *temp;

    if (L.head == NULL) {
        printf("List is empty!\n");
    } else {
        temp = L.head;
        L.head = L.head->next;

        free(temp);
        L.count--;
    }
    return L;
}

List deleteLast(List L) {
    Node *current;

    if (L.head == NULL) {
        printf("List is empty!\n");
    } else if (L.head->next == NULL) {
        free(L.head);
        L.head = NULL;
        L.count--;
    } else {
        current = L.head;
        while (current->next->next != NULL && L.count >= 0) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;

        L.count--;
    }
    return L;
}

List deletePos(List L, int index) {
    Node *current;
    Node *temp;

    if (index < 0 || index >= L.count) {
        printf("Invalid position!\n");
    } else if (index == 0) {
        L = deleteStart(L);
    } else {
        current = L.head;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);

        L.count--;
    }
    return L;
}

Person retrieve(List L, int index) {
    Node *current;
    Person temp;

    temp.id = -1;
    strcpy(temp.name, "INVALID");
    temp.age = -1;

    if (index < 0 || index >= L.count) {
        printf("Invalid position!\n");
    } else {
        current = L.head;
        for (int i = 0; i < index && current != NULL; i++) {
            current = current->next;
        }
        temp = current->data;
    }
    return temp;
}

int locate(List L, int id) {

    Node *current = L.head;
    int index = 0;
    int pos = -1;

    while (current != NULL && pos == -1) {
        if (current->data.id == id) {
            pos = index;
        }
        current = current->next;
        index++;
    }
    return pos;
}

void display(List L) {
    Node *current = L.head;
    printf("\nList: ");

    while (current != NULL && L.count >= 0) {
        printf("[ID:%d Name:%s Age:%d] -> ",
               current->data.id,
               current->data.name,
               current->data.age);

        current = current->next;
    }
    printf("NULL (count=%d)\n", L.count);
}

int main() {
    List L;
    Person p;

    L = initialize(L);

    p.id=101; strcpy(p.name,"Alice"); p.age=20;
    L = insertFirst(L,p);

    p.id=110; strcpy(p.name,"Bob"); p.age=22;
    L = insertFirst(L,p);

    p.id=120; strcpy(p.name,"Charlie"); p.age=21;
    L = insertLast(L,p);

    display(L);

    L = deleteStart(L);
    display(L);

    p.id=130; strcpy(p.name,"David"); p.age=23;
    L = insertPos(L,p,1);
    display(L);

    printf("Locate ID 130: %d\n", locate(L,130));

    Person temp = retrieve(L,1);

    printf("Retrieve index 1 -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    L = empty(L);
    display(L);

    return 0;
}