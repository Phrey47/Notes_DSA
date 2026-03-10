// // Variation 1: Linked List Stack Implementation in C
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct node {
//     int data;
//     struct node* next;
// } Node;

// typedef struct {
//     Node* top;  
// } Stack;

// Stack* initialize();
// bool isFull(Stack* s);
// bool isEmpty(Stack* s);
// bool push(Stack* s, int value);
// int pop(Stack* s);
// int peek(Stack* s);
// void display(Stack* s);

// Stack* initialize() {
//     Stack* s = (Stack*)malloc(sizeof(Stack));
//     s->top = NULL;
//     return s;
// }

// bool isFull(Stack* s) {
//     return false;
// }

// bool isEmpty(Stack* s) {
//     return (s->top == NULL);
// }

// bool push(Stack* s, int value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed!\n");
//         return false;
//     }
//     newNode->data = value;
//     newNode->next = s->top;  
//     s->top = newNode;      
//     return true;
// }

// int pop(Stack* s) {
//     if (isEmpty(s)) {
//         printf("Stack Underflow! Cannot pop.\n");
//         return -1;
//     }
//     Node* temp = s->top;
//     int value = temp->data;
//     s->top = temp->next;  
//     free(temp);
//     return value;
// }

// int peek(Stack* s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty.\n");
//         return -1;
//     }
//     return s->top->data;
// }

// void display(Stack* s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     printf("Stack (top -> bottom): ");
//     Node* current = s->top;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     Stack* S = initialize();

//     push(S, 1);
//     push(S, 3);
//     push(S, 5);
//     display(S);  // top -> 5 -> 3 -> 1

//     push(S, 4);
//     display(S);  // top -> 4 -> 5 -> 3 -> 1

//     printf("Popped: %d\n", pop(S));
//     display(S);  // top -> 5 -> 3 -> 1

//     printf("Peek: %d\n", peek(S));

//     return 0;
// }

// Variation 1: Linked List Stack Implementation in C with Person Struct
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
bool push(Stack* s, Person value);
Person pop(Stack* s);
Person peek(Stack* s);
void display(Stack* s);

Stack* initialize() {
    Stack* s;
    s = (Stack*)malloc(sizeof(Stack));

    if (s != NULL) {
        s->top = NULL;
    }

    return s;
}

bool isFull(Stack* s) {
    bool result;
    result = false;   

    return result;
}

bool isEmpty(Stack* s) {
    bool result;

    if (s->top == NULL) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

bool push(Stack* s, Person value) {
    Node* newNode;
    bool success;
    success = false;

    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    } else {
        newNode->data = value;
        newNode->next = s->top;
        s->top = newNode;

        success = true;
    }
    return success;
}

Person pop(Stack* s) {
    Person temp;
    Node* deleteNode;

    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");

    } else {
        deleteNode = s->top;
        temp = deleteNode->data;

        s->top = deleteNode->next;
        free(deleteNode);
    }
    return temp;
}

Person peek(Stack* s) {
    Person temp;

    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        temp = s->top->data;
    }
    return temp;
}

void display(Stack* s) {
    Node* current;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack (top -> bottom):\n");
        current = s->top;
        while (current != NULL && current->data.id != -9999) {

            printf("ID:%d | Name:%s | Age:%d\n",
                   current->data.id,
                   current->data.name,
                   current->data.age);

            current = current->next;
        }
    }
}

int main() {
    Stack* S;
    Person p;
    Person temp;

    S = initialize();

    p.id = 101; strcpy(p.name,"Alice"); p.age = 20;
    push(S,p);

    p.id = 102; strcpy(p.name,"Bob"); p.age = 22;
    push(S,p);

    p.id = 103; strcpy(p.name,"Charlie"); p.age = 21;
    push(S,p);

    display(S);

    p.id = 104; strcpy(p.name,"David"); p.age = 23;
    push(S,p);

    display(S);

    temp = pop(S);
    printf("\nPopped -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    display(S);

    temp = peek(S);
    printf("\nPeek -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    return 0;
}