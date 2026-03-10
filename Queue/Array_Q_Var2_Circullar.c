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
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, Person value);
Person dequeue(Queue* q);
Person frontElement(Queue* q);
void display(Queue* q);

Queue* initialize() {
    Queue* q;

    q = (Queue*)malloc(sizeof(Queue));

    if (q != NULL) {
        q->front = 1;
        q->rear = 0;
    }
    return q;
}

bool isEmpty(Queue* q) {
    bool result;

    if (q->front == (q->rear + 1) % MAX) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool isFull(Queue* q) {
    bool result;

    if (q->front == (q->rear + 2) % MAX) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void enqueue(Queue* q, Person value) {

    if (isFull(q)) {
        printf("Queue is full.\n");

    } else {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    }
}

Person dequeue(Queue* q) {
    Person temp;
    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        temp = q->items[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return temp;
}

Person frontElement(Queue* q) {
    Person temp;
    temp.id = -1;
    strcpy(temp.name,"INVALID");
    temp.age = -1;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        temp = q->items[q->front];
    }
    return temp;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("\nQueue contents (front -> rear):\n");
        
        int i = q->front;
        while (i != (q->rear + 1) % MAX && i < MAX) {
            printf("ID:%d | Name:%s | Age:%d\n",
                   q->items[i].id,
                   q->items[i].name,
                   q->items[i].age);

            i = (i + 1) % MAX;
        }
    }
}

int main() {
    Queue* q;
    Person p;
    Person temp;

    q = initialize();

    p.id=101; strcpy(p.name,"Alice"); p.age=20;
    enqueue(q,p);

    p.id=110; strcpy(p.name,"Bob"); p.age=22;
    enqueue(q,p);

    p.id=120; strcpy(p.name,"Charlie"); p.age=21;
    enqueue(q,p);

    p.id=130; strcpy(p.name,"David"); p.age=23;
    enqueue(q,p);


    display(q);

    temp = frontElement(q);
    printf("\nFront element -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    temp = dequeue(q);
    printf("\nDequeued -> ID:%d Name:%s Age:%d\n",
           temp.id,temp.name,temp.age);

    display(q);

    return 0;
}