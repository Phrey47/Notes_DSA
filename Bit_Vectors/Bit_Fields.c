#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
}Set;

void init(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < 8) 
        return (set.field & (1 << element)) != 0;
    return false;
}

Set SetUnion(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set SetIntersection(Set A, Set B){
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set SetDifference(Set A, Set B){
    Set result;
    result.field = A.field & (~B.field);
    return result;
}

void display(Set set){
    int first = 1;
    printf("{");
    for(int i = 0; i < 8; i++){
        if(find(set, i)){
            if(!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main(){
    Set A, B, C;

    init(&A);
    init(&B);
    init(&C);

    insert(&A, 2);
    insert(&A, 6);
    insert(&A, 3);

    insert(&B, 7);
    insert(&B, 3);
    insert(&B, 5);

    printf("Set A = ");
    display(A);
    printf("Set B = ");
    display(B);

    C = SetUnion(A, B);
    printf("A ∪ B = ");
    display(C);
    C = SetIntersection(A, B);
    printf("A ∩ B = ");
    display(C);
    C = SetDifference(A, B);
    printf("A - B = ");
    display(C);

    return 0;
}

