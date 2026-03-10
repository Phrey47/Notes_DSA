// //Variation 2
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct node {
//     int data;
//     struct node *next;
// } Node;

// typedef struct {
//     Node *head;
//     int count;
// } List;

// List* initialize();
// void empty(List *list);
// void insertFirst(List *list, int data);
// void insertLast(List *list, int data);
// void insertPos(List *list, int data, int index);
// void deleteStart(List *list);
// void deleteLast(List *list);
// void deletePos(List *list, int index);
// int retrieve(List *list, int index);
// int locate(List *list, int data);
// void display(List *list);

// List* initialize() {
//     List *list = (List*)malloc(sizeof(List));
//     if (list == NULL) return NULL;
//     list->head = NULL;
//     list->count = 0;
//     return list;
// }

// void empty(List *list) {
//     Node *current = list->head;
//     Node *temp;
//     while (current != NULL) {
//         temp = current;
//         current = current->next;
//         free(temp);
//     }
//     list->head = NULL;
//     list->count = 0;
// }

// void insertFirst(List *list, int data) {
//     Node *newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = list->head;
//     list->head = newNode;
//     list->count++;
// }

// void insertLast(List *list, int data) {
//     Node *newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (list->head == NULL) {
//         list->head = newNode;
//     } else {
//         Node *current = list->head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
//     list->count++;
// }

// void insertPos(List *list, int data, int index) {
//     if (index < 0 || index > list->count) return;

//     if (index == 0) {
//         insertFirst(list, data);
//     } else if (index == list->count) {
//         insertLast(list, data);
//     } else {
//         Node *newNode = (Node*)malloc(sizeof(Node));
//         newNode->data = data;

//         Node *current = list->head;
//         for (int i = 0; i < index - 1; i++) {
//             current = current->next;
//         }

//         newNode->next = current->next;
//         current->next = newNode;
//         list->count++;
//     }
// }

// void deleteStart(List *list) {
//     if (list->head == NULL) return;

//     Node *temp = list->head;
//     list->head = list->head->next;
//     free(temp);
//     list->count--;
// }

// void deleteLast(List *list) {
//     if (list->head == NULL) return;

//     if (list->head->next == NULL) {
//         free(list->head);
//         list->head = NULL;
//     } else {
//         Node *current = list->head;
//         while (current->next->next != NULL) {
//             current = current->next;
//         }
//         free(current->next);
//         current->next = NULL;
//     }
//     list->count--;
// }

// void deletePos(List *list, int index) {
//     if (index < 0 || index >= list->count) return;

//     if (index == 0) {
//         deleteStart(list);
//     } else {
//         Node *current = list->head;
//         for (int i = 0; i < index - 1; i++) {
//             current = current->next;
//         }
//         Node *temp = current->next;
//         current->next = temp->next;
//         free(temp);
//         list->count--;
//     }
// }

// int retrieve(List *list, int index) {
//     if (index < 0 || index >= list->count) return -1;

//     Node *current = list->head;
//     for (int i = 0; i < index; i++) {
//         current = current->next;
//     }
//     return current->data;
// }

// int locate(List *list, int data) {
//     Node *current = list->head;
//     int index = 0;
//     while (current != NULL) {
//         if (current->data == data) return index;
//         current = current->next;
//         index++;
//     }
//     return -1;
// }

// void display(List *list) {
//     Node *current = list->head;
//     printf("List: ");
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL (count=%d)\n", list->count);
// }

// int main() {
//     List *list = initialize();

//     insertFirst(list, 5);
//     insertFirst(list, 6);
//     insertFirst(list, 2);
//     display(list);  // 2 -> 6 -> 5

//     insertLast(list, 7);
//     display(list);  // 2 -> 6 -> 5 -> 7

//     insertPos(list, 9, 2);
//     display(list);  // 2 -> 6 -> 9 -> 5 -> 7

//     deleteStart(list);
//     display(list);  // 6 -> 9 -> 5 -> 7

//     deleteLast(list);
//     display(list);  // 6 -> 9 -> 5

//     deletePos(list, 1);
//     display(list);  // 6 -> 5

//     printf("Retrieve index 1: %d\n", retrieve(list, 1));
//     printf("Locate data 6: %d\n", locate(list, 6));

//     empty(list);
//     display(list);

//     free(list);
//     return 0;
// }

// Variation 2 with struct Person
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

List* initialize();
void empty(List *list);
void insertFirst(List *list, Person data);
void insertLast(List *list, Person data);
void insertPos(List *list, Person data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
Person retrieve(List *list, int index);
int locate(List *list, int id);
void display(List *list);

List* initialize() {
    List *list = (List*)malloc(sizeof(List));

    if (list == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    list->head = NULL;
    list->count = 0;

    return list;
}

void empty(List *list) {
    Node *current = list->head;
    Node *temp;

    while (current != NULL && list->count >= 0) {

        temp = current;
        current = current->next;

        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, Person data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;

        list->count++;
    }
}

void insertLast(List *list, Person data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *current;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        newNode->data = data;
        newNode->next = NULL;
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            current = list->head;
            while (current->next != NULL && list->count >= 0) {
                current = current->next;
            }
            current->next = newNode;
        }
        list->count++;
    }
}

void insertPos(List *list, Person data, int index) {
    Node *newNode;
    Node *current;

    if (index < 0 || index > list->count) {
        printf("Invalid position!\n");
    } else if (index == 0) {
        insertFirst(list, data);
    } else if (index == list->count) {
        insertLast(list, data);
    } else {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
        }
        else {
            newNode->data = data;
            current = list->head;

            for (int i = 0; i < index - 1 && current != NULL; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;

            list->count++;
        }
    }
}

void deleteStart(List *list) {
    Node *temp;

    if (list->head == NULL) {
        printf("List is empty!\n");
    } else {
        temp = list->head;
        list->head = list->head->next;

        free(temp);

        list->count--;
    }
}

void deleteLast(List *list) {
    Node *current;

    if (list->head == NULL) {
        printf("List is empty!\n");
    } else if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->count--;
    } else {
        current = list->head;
        while (current->next->next != NULL && list->count >= 0) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;

        list->count--;
    }
}

void deletePos(List *list, int index) {
    Node *current;
    Node *temp;

    if (index < 0 || index >= list->count) {
        printf("Invalid position!\n");
    } else if (index == 0) {
        deleteStart(list);
    } else {
        current = list->head;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);

        list->count--;
    }
}

Person retrieve(List *list, int index) {
    Node *current;
    Person temp;

    temp.id = -1;
    strcpy(temp.name, "INVALID");
    temp.age = -1;

    if (index < 0 || index >= list->count) {
        printf("Invalid position!\n");
    } else {
        current = list->head;
        for (int i = 0; i < index && current != NULL; i++) {
            current = current->next;
        }
        temp = current->data;
    }
    return temp;
}

int locate(List *list, int id) {
    Node *current = list->head;
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

void display(List *list) {
    Node *current = list->head;

    printf("\nList: ");
    while (current != NULL && list->count >= 0) {
        printf("[ID:%d Name:%s Age:%d] -> ",
               current->data.id,
               current->data.name,
               current->data.age);

        current = current->next;
    }
    printf("NULL (count=%d)\n", list->count);
}

int main() {
    List *list = initialize();
    Person p;

    p.id=101; strcpy(p.name,"Alice"); p.age=20;
    insertFirst(list,p);

    p.id=110; strcpy(p.name,"Bob"); p.age=22;
    insertFirst(list,p);

    p.id=120; strcpy(p.name,"Charlie"); p.age=21;
    insertLast(list,p);

    display(list);

    deleteStart(list);
    display(list);

    p.id=130; strcpy(p.name,"David"); p.age=23;
    insertPos(list,p,1);
    display(list);

    printf("Locate ID 130: %d\n", locate(list,130));

    Person temp = retrieve(list,1);

    printf("Retrieve index 1 -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    empty(list);
    display(list);

    free(list);

    return 0;
}