#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define SIZE 256
#define EMPTY ""  

typedef struct {
    char name[SIZE];
    char job[SIZE];
    int age;
    bool occupied; 
} Entry;

Entry table[MAX];

int hash(char* name) {
    int i, hash_value = 0;
    for(i = 0; name[i] != '\0'; i++) {
        hash_value += name[i];
        hash_value = (hash_value * 203) % MAX;
    }
    return hash_value;
}

void init() {
    for(int i = 0; i < MAX; i++) {
        table[i].occupied = false;
        table[i].name[0] = '\0';
    }
}

bool insert(char* name, char* job, int age) {
    int index = hash(name);
    int start = index;

    do {
        if(!table[index].occupied) {
            strcpy(table[index].name, name);
            strcpy(table[index].job, job);
            table[index].age = age;
            table[index].occupied = true;
            return true;
        }
        index = (index + 1) % MAX;  
    } while(index != start);

    return false;
}

Entry* lookup(char* name) {
    int index = hash(name);
    int start = index;

    do {
        if(table[index].occupied && strcmp(table[index].name, name) == 0)
            return &table[index];

        index = (index + 1) % MAX;
    } while(index != start);

    return NULL; 
}

bool delete(char* name) {
    Entry* entry = lookup(name);
    if(entry != NULL) {
        entry->occupied = false;
        entry->name[0] = '\0';
        return true;
    }
    return false;
}

void display() {
    for(int i = 0; i < MAX; i++) {
        if(table[i].occupied)
            printf("%d | Name: %s, Job: %s, Age: %d\n", i, table[i].name, table[i].job, table[i].age);
        else
            printf("%d --- empty\n", i);
    }
}

int main() {
    init();

    insert("Ronald", "Unemployed", 21);
    insert("Toji", "Unemployed", 23);
    insert("Hump", "Engineer", 25);
    insert("Seb", "Programmer", 28);
    insert("Ken", "Unemployed", 23);
    insert("Peter", "Engineer", 25);

    display();

    Entry* found = lookup("Hump");
    if(found)
        printf("\nFound: %s, %s, %d\n", found->name, found->job, found->age);

    delete("Toji");
    printf("\nAfter deletion:\n");
    display();

    return 0;
}
