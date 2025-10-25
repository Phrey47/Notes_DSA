#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// write your functions here...

Set* createSet(){
    Set* newSet = malloc(sizeof(Set));
    newSet->head = NULL;
    newSet->size = 0;
    return newSet;
}

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell){
    Node* trav = set->head;
    
    while(trav != NULL){
        if(strcmp(trav->spell, spell) == 0){
            return false;
        }
        trav = trav->next;
    }
    
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = set->head;
    set->head = newNode;
    set->size++;

    return true;
}

// Remove a spell from the set
bool removeSpell(Set** set, String spell){
    Node* trav = (*set)->head;
    
    if((*set)->head == NULL){
        return false;
    }
    
    if(strcmp(trav->spell, spell) == 0){
        Node* DeleteNode = trav;
        (*set)->head = DeleteNode->next;
        free(DeleteNode);
        (*set)->size--;
        return true;
    }
    
    for(;trav->next != NULL && strcmp(trav->spell, spell) != 0;){
        trav = trav->next;
    }
    
    if(trav->next == NULL){
        return false;
    }
    
    Node* DeleteNode;
    DeleteNode = trav->next;
    trav->next = DeleteNode->next;
    free(DeleteNode);
    (*set)->size--;
    return true;
}

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell){
    Node* trav;
    
    for(trav = set->head; trav != NULL;trav = trav->next){
        if(strcmp(trav->spell, spell) == 0){
            return true;
        }
    }
    
    
    return false;
}

// Print all spells in the set
void printSet(Set* set){
    Node* trav;
    int i = 1;
    for(trav = set->head;trav != NULL;trav = trav->next){
        printf("  %d. %s\n", i, trav->spell);
        i++;
    }
    
}

// Free all memory associated with the set
void destroySet(Set* set){
    Node* trav;
    
    for(trav = set->head;trav != NULL;){
        Node* temp;
        temp = trav;
        trav = trav->next;
        free(temp);
    }
    
    set->head = NULL;
    set->size = 0;
    free(set);
}

Set* unionSets(Set* set1, Set* set2){
    Set* set3 = createSet();
    Node* trav;
    
     for(trav = set1->head;trav != NULL;trav = trav->next){
        addSpell(set3, trav->spell);
    }
    
     for(trav = set2->head;trav != NULL;trav = trav->next){
        addSpell(set3, trav->spell);
    }
  
    
    return set3;
}

Set* intersectSets(Set* set1, Set* set2){
    Set* set3 = createSet();
    Node* trav1, *trav2;
    
    for(trav1 = set1->head;trav1 != NULL;trav1 = trav1->next){
        for(trav2 = set2->head;trav2 != NULL;trav2 = trav2->next){
            if(strcmp(trav1->spell, trav2->spell) == 0){
                addSpell(set3, trav1->spell);
                break;
            }
        }
    }
    
    return set3;
}
