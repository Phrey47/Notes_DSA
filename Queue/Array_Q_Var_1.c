// #include <stdio.h>
// #include <stdbool.h>

// #define MAX 5   // queue capacity

// typedef struct {
//     int items[MAX];
//     int front;
//     int rear;
// } Queue;

// // Initialize queue (void version)
// void initQueue(Queue *q) {
//     q->front = -1;
//     q->rear = -1;
// }

// // Check if queue is empty
// bool isEmpty(Queue *q) {
//     return (q->front == -1);
// }

// // Check if queue is full (circular condition)
// bool isFull(Queue *q) {
//     return ((q->rear + 1) % MAX == q->front);
// }

// // Enqueue operation
// void enqueue(Queue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue Overflow!\n");
//         return;
//     }
//     if (isEmpty(q)) {
//         q->front = 0;
//     }
//     q->rear = (q->rear + 1) % MAX;
//     q->items[q->rear] = value;
//     printf("%d enqueued\n", value);
// }

// // Dequeue operation
// int dequeue(Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue Underflow!\n");
//         return -1;
//     }

//     int value = q->items[q->front];

//     if (q->front == q->rear) {
//         // Queue becomes empty
//         q->front = -1;
//         q->rear = -1;
//     } else {
//         q->front = (q->front + 1) % MAX;
//     }
//     return value;
// }

// // Peek at front element
// int peek(Queue *q) {
//     if (isEmpty(q)) return -1;
//     return q->items[q->front];
// }

// // Display all queue elements
// void display(Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty.\n");
//         return;
//     }
//     printf("Queue: ");
//     int i = q->front;
//     while (1) {
//         printf("%d ", q->items[i]);
//         if (i == q->rear) break;
//         i = (i + 1) % MAX;
//     }
//     printf("\n");
// }

// // Main function to test
// int main() {
//     Queue q;
//     initQueue(&q);   // Using void initQueue

//     enqueue(&q, 10);
//     enqueue(&q, 20);
//     enqueue(&q, 30);
//     enqueue(&q, 40);
//     display(&q);

//     printf("Dequeued: %d\n", dequeue(&q));
//     display(&q);

//     enqueue(&q, 50);
//     display(&q);

//     printf("Front element: %d\n", peek(&q));

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Queue* initialize(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

bool isFull(Queue* Q){
    return false;
}

bool isEmpty(Queue* Q){
    return Q->front == NULL;
}

void enqueue(Queue* Q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(isEmpty(Q)){
        Q->front = newNode;
        Q->rear = newNode;
    }else{
         Q->rear->next = newNode;
         Q->rear = newNode;
    }

}

int dequeue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }

    Node* temp = Q->front;
    int value = Q->front->data;
    Q->front = Q->front->next;

     if(Q->front == NULL){
        Q->rear = NULL;
    }

    free(temp);
    return value;
}

int front(Queue* Q){
    if(Q->front == NULL){
        return -1;
    }

    return Q->front->data;
}

void display(Queue* Q){
    if(isEmpty(Q)){
        return;
    }
    Node* trav = Q->front;

    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }

    printf("\n");
}


int main(){
    Queue* Q = initialize();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    display(Q);
    dequeue(Q);
    dequeue(Q);
    display(Q);
}