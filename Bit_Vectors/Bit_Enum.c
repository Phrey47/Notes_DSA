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

void insertSet(Set s, int index){
    if(index >= 0 && index < SIZE){
        s[index] = TRUE;
    }
}

void AssignSet(Set A, Set B){
    int i;
    for(i = 0;i < SIZE;i++){
        A[i] = B[i];
    }
}

int minSet(Set s){
    int i;
    for(i = 0;i < SIZE;i++){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}

int maxSet(Set s){
    int i;
    for(i = SIZE - 1;i >= 0;i--){
        if(s[i] == TRUE){
            return i;
        }
    }
    return -1;
}

int equalSet(Set A, Set B){
    int i;
    for(i = 0;i < SIZE;i++){
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
    int i;
    for(i = 0;i < SIZE;i++){
       C[i] = A[i] || B[i];
    }
}

void SetIntersection(Set A, Set B, Set C){
    int i;
    for(i = 0;i < SIZE;i++){
       C[i] = A[i] && B[i];
    }
}

void SetDifference(Set A, Set B, Set C){
    int i;
    for(i = 0;i < SIZE;i++){
       C[i] = A[i] && !B[i];
    }
}

void display(Set s) {
    int i;
    int comma = 1;
    printf("{");
    for (i = 0; i < SIZE; i++) {
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
    Set A, B;

    initSet(A);
    initSet(B);

    insertSet(A, 3);
    insertSet(A, 1);
    insertSet(A, 7);

    insertSet(B, 9);
    insertSet(B, 3);
    insertSet(B, 1);

    display(A);
    display(B);

    return 0;
}

void initSet(Set s){
    int i;
    for(i = 0;i < SIZE;i++){
        s[i] = FALSE;
    }
}
