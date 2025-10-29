#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10
#define SIZE 256

typedef struct node{
    char name[SIZE];
    char job[SIZE];
    int age;
    struct node* next;
}Node;

typedef Node* dict[MAX];

int hash(char* name){
    int i, hash_value = 0;
    for(i = 0;name[i] != '\0';i++){
        hash_value += name[i];
        hash_value = (hash_value * 203) % MAX;
    }
    return hash_value;
}

void init(dict table){
    int i;

    for(i = 0;i < MAX;i++){
        table[i] = NULL;
    }
}

void insert(dict table, char* name, char* job, int age){
    int index = hash(name);
    
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;
    strcpy(newNode->name, name);
    strcpy(newNode->job, job);
    newNode->age = age;
    newNode->next = table[index];
    table[index] = newNode;
}

void insertLast(dict table, char* name, char* job, int age){
    int index = hash(name);

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    strcpy(newNode->name, name);
    strcpy(newNode->job, job);
    newNode->age = age;
    newNode->next = NULL;

    Node** trav;
    for(trav = &(table[index]); *trav != NULL;trav = &(*trav)->next){}
    
    *trav = newNode;
}

Node* lookup(dict table, char* name){
    int index = hash(name);
    Node* temp;
    for(temp = table[index];temp != NULL && strcmp(temp->name, name) != 0;){
        temp = temp->next;
    }

    return temp;
}

Node* delete(dict table, char* name){
    int index = hash(name);
    Node* temp, *prev = NULL;
    for(temp = table[index];temp != NULL && strcmp(temp->name, name) != 0;){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return NULL;
    if(prev == NULL){
        table[index] = temp->next;
    }else{
        prev->next = temp->next;
    }
    
    return temp;
}

void display(dict table){
    int i;

    for(i = 0;i < MAX;i++){
        if(table[i] == NULL){
            printf("\n%d ---",i);
        }else{
            printf("\n%d | ", i);
            Node* trav = table[i];
            while(trav != NULL){
                printf("Name: %s, Job: %s, Age: %d -> ", trav->name, trav->job, trav->age);
                trav = trav->next;
            }
        }
    }
}

int main(){
    dict table;
    init(table);
    insert(table, "Ronald", "Unemployed", 21);
    insert(table, "Toji", "Unemployed", 23);
    insert(table, "Hump", "Engineer", 25);
    insertLast(table, "Seb", "Programmer", 28);
    insert(table, "Ken", "Unemployed", 23);
    insert(table, "Peter", "Engineer", 25);
    display(table);
    return 0;
} 