#include <stdio.h>
#define SIZE 30

typedef enum{ FALSE, TRUE } Boolean;
typedef Boolean Set[SIZE];

Boolean isMember(Set s, int index){
    if(index >= 0 && index < SIZE){
        return s[index];
    }
    return FALSE;
}

void initSet(Set s){

    for(int i = 0;i < SIZE;i++){
        s[i] = FALSE;
    }
}

void insertSet(Set s, int index){
    if(index >= 0 && index < SIZE){
        s[index] = TRUE;
    }
}
// not sure if necessary
void AssignSet(Set A, Set B){
    
    for(int i = 0;i < SIZE;i++){
        A[i] = B[i];
    }
}
// not sure if necessary
int minSet(Set s){
    
    for(int i = 0;i < SIZE;i++){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}
// not sure if necessary
int maxSet(Set s){
    
    for(int i = SIZE - 1;i >= 0;i--){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}
// not sure if necessary
int equalSet(Set A, Set B){
    
    for(int i = 0;i < SIZE;i++){
        if(A[i] != B[i]){
            return 0;
        }
    }
    return 1;
}

int findSet(Set s, int index){
    if(index >= 0 && index < SIZE && s[index] == TRUE){
        return index;
    }
    return -1;
}

void deleteSet(Set s, int index){
    if(index >= 0  && index < SIZE && s[index] == TRUE){
        s[index] = FALSE;
    }
}

void SetUnion(Set A, Set B, Set C){
    
    for(int i = 0;i < SIZE;i++){
       C[i] = A[i] || B[i];
    }
}

void SetIntersection(Set A, Set B, Set C){
    
    for(int i = 0;i < SIZE;i++){
       C[i] = A[i] && B[i];
    }
}

void SetDifference(Set A, Set B, Set C){
    
    for(int i = 0;i < SIZE;i++){
       C[i] = A[i] && !B[i];
    }
}

void display(Set s) {
    
    int comma = 1;
    printf("{");
    for (int i = 0; i < SIZE; i++) {
        if (s[i] == TRUE) {
            if(!comma){
                printf(", ");
            }
            printf("%d", i);
            comma = 0;
        }
    }
    printf("}\n");
}  

int main(){
    Set A, B, C;

    initSet(A);
    initSet(B);

    insertSet(A, 3);
    insertSet(A, 1);
    insertSet(A, 7);

    insertSet(B, 9);
    insertSet(B, 3);
    insertSet(B, 1);

    printf("Set A = ");
    display(A);
    printf("Set B = ");
    display(B);

    SetUnion(A, B, C);
    printf("A ∪ B = ");
    display(C);
    SetIntersection(A, B, C);
    printf("A ∩ B = ");
    display(C);
    SetDifference(A, B, C);
    printf("A - B = ");
    display(C);

    return 0;
}

