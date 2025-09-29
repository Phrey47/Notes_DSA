#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10   // Maximum size of stack

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function prototypes
void initializeStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);
bool search(Stack *s, int value);

// Initialize stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Push element into stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top--;
}

// Peek at top element
int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

// Display all elements
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top -> bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

// Search for an element
bool search(Stack *s, int value) {
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i] == value) {
            return true;
        }
    }
    return false;
}

// Main program
int main() {
    Stack s;
    initializeStack(&s);

    // Push elements
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    // Display stack
    display(&s);

    // Peek at top element
    printf("Top element: %d\n", peek(&s));

    // Pop one element
    printf("Popped: %d\n", pop(&s));
    display(&s);

    // Search for value
    if (search(&s, 20)) 
        printf("Found 20 in stack!\n");
    else 
        printf("20 not found!\n");

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 10

// typedef struct{
//     int items[MAX];
//     int top;
// }Stack;

// // Stack* init(){
// //     Stack* newStack = malloc(sizeof(Stack));
// //     newStack->top = -1;

// //     return newStack;
// // }
// void init(Stack *s) {
//     s->top = -1;
// }

// void push(Stack* S, int data){
//     if(S->top > MAX){
//         printf("Overflow!\n");
//         return;
//     }
//     S->top++;
//     S->items[S->top] = data;
// }

// void pop(Stack* S){
//     if(S->top < 0){
//         printf("Underflow!\n");
//         return;
//     }
//     S->top--;
// }

// void peek(Stack* S){
//     if(S->top == -1) return;
    
//     printf("Top of the Stack is %d.", S->items[S->top]);
// }

// void display(Stack* S){
//     int i;

//     for(i = S->top;i >= 0;i--){
//         printf("%d ", S->items[i]);
//     }

//     printf("\n");
// }

// int main(){
//     Stack S; 
//     init(&S);

//     push(&S, 1);
//     push(&S, 3);
//     push(&S, 5);
//     push(&S, 6);
//     push(&S, 7);
//     display(&S);
//     pop(&S);
//     display(&S);
// }