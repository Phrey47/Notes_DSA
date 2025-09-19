#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
bool enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

// Initialize queue
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if queue is full (LL queue is never full unless malloc fails)
bool isFull(Queue* q) {
    return false;
}

// Check if queue is empty
bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation
bool enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return true;
}

// Dequeue operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) { // queue became empty
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// Get front element
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front -> rear): ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test
int main() {
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    display(Q);  // 1 -> 3 -> 5

    enqueue(Q, 4);
    display(Q);  // 1 -> 3 -> 5 -> 4

    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);  // 3 -> 5 -> 4

    printf("Front element: %d\n", front(Q));

    return 0;
}
