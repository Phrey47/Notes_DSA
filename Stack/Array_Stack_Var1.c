// //Variant 1: Basic Stack Implementation using Array
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define MAX 10  

// typedef struct {
//     int items[MAX];
//     int top;
// } Stack;

// void initializeStack(Stack *s);
// bool isFull(Stack *s);
// bool isEmpty(Stack *s);
// void push(Stack *s, int value);
// int pop(Stack *s);
// int peek(Stack *s);
// void display(Stack *s);
// bool search(Stack *s, int value);

// void initializeStack(Stack *s) {
//     s->top = -1;
// }

// bool isFull(Stack *s) {
//     return s->top == MAX - 1;
// }

// bool isEmpty(Stack *s) {
//     return s->top == -1;
// }

// void push(Stack *s, int value) {
//     if (isFull(s)) {
//         printf("Stack is full.\n");
//         return;
//     }
//     s->top++;
//     s->items[s->top] = value;
// }

// int pop(Stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty.\n");
//         return -1;
//     }
//     return s->top--;
// }

// int peek(Stack *s) {
//     if (isEmpty(s)) return -1;
//     return s->items[s->top];
// }

// void display(Stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     printf("Stack contents (top -> bottom):\n");
//     for (int i = s->top; i >= 0; i--) {
//         printf("%d\n", s->items[i]);
//     }
// }

// bool search(Stack *s, int value) {
//     for (int i = 0; i <= s->top; i++) {
//         if (s->items[i] == value) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     Stack s;
//     initializeStack(&s);

//     push(&s, 10);
//     push(&s, 20);
//     push(&s, 30);
//     push(&s, 40);

//     display(&s);

//     printf("Top element: %d\n", peek(&s));

//     printf("Popped: %d\n", pop(&s));
//     display(&s);

//     if (search(&s, 20)) 
//         printf("Found 20 in stack!\n");
//     else 
//         printf("20 not found!\n");

//     return 0;
// }

//Variant 1: Stack Implementation using Array with Person Struct
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct {
    Person items[MAX];
    int top;
} Stack;

void initializeStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, Person value);
Person pop(Stack *s);
Person peek(Stack *s);
void display(Stack *s);
bool search(Stack *s, int id);

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    bool result;

    if (s->top == MAX - 1) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool isEmpty(Stack *s) {
    bool result;

    if (s->top == -1) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void push(Stack *s, Person value) {
    if (isFull(s)) {

        printf("Stack is full.\n");

    } else {
        //s->top++;
        s->items[++s->top] = value;
    }
}

Person pop(Stack *s) {
    Person temp;

    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");

    } else {
        temp = s->items[s->top];
        s->top--;
    }
    return temp;
}

Person peek(Stack *s) {
    Person temp;

    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");

    } else {
        temp = s->items[s->top];
    }
    return temp;
}

void display(Stack *s) {
    int i;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("\nStack contents (top -> bottom):\n");
        for (i = s->top; i >= 0 && i < MAX; i--) {

            printf("ID:%d | Name:%s | Age:%d\n",
                   s->items[i].id,
                   s->items[i].name,
                   s->items[i].age);
        }
    }
}

bool search(Stack *s, int id) {
    int i = 0;
    bool found = false;

    while (i <= s->top && found == false) {
        if (s->items[i].id == id) {
            found = true;
        }
        i++;
    }
    return found;
}

int main() {
    Stack s;
    Person p;
    Person temp;

    initializeStack(&s);

    p.id=101; strcpy(p.name,"Alice"); p.age=20;
    push(&s,p);

    p.id=110; strcpy(p.name,"Bob"); p.age=22;
    push(&s,p);

    p.id=120; strcpy(p.name,"Charlie"); p.age=21;
    push(&s,p);

    p.id=130; strcpy(p.name,"David"); p.age=23;
    push(&s,p);

    display(&s);

    temp = peek(&s);
    printf("\nTop element -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    temp = pop(&s);
    printf("\nPopped -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    display(&s);

    if (search(&s,110)) {
        printf("\nFound ID 110 in stack!\n");
    } else {
        printf("\nID 110 not found!\n");
    }

    return 0;
}