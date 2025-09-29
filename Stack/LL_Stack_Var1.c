#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;   // pointer to the top node
} Stack;

// Function prototypes
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
bool push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

// Initialize a new stack
Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Check if stack is full (LL stack is never full unless malloc fails)
bool isFull(Stack* s) {
    return false;
}

// Check if stack is empty
bool isEmpty(Stack* s) {
    return (s->top == NULL);
}

// Push an element onto the stack
bool push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    newNode->data = value;
    newNode->next = s->top;  // link new node to old top
    s->top = newNode;        // update top
    return true;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;  // move top down
    free(temp);
    return value;
}

// Peek at the top element
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

// Display all elements in the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing
int main() {
    Stack* S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 5);
    display(S);  // top -> 5 -> 3 -> 1

    push(S, 4);
    display(S);  // top -> 4 -> 5 -> 3 -> 1

    printf("Popped: %d\n", pop(S));
    display(S);  // top -> 5 -> 3 -> 1

    printf("Peek: %d\n", peek(S));

    return 0;
}
