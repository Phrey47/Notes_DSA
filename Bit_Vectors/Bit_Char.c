#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BITS 8   

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element >= 0 && element < MAX_BITS){
        *set |= (1 << element);
    }
}

void deleteElem(unsigned char *set, int element){
    if(element >= 0 && element < MAX_BITS){
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element){
    if(element >= 0 && element < MAX_BITS) 
        return (set & (1 << element)) != 0;
    return false;
}

unsigned char SetUnion(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char SetIntersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char SetDifference(unsigned char A, unsigned char B){
    return A & (~B);
}

void display(unsigned char set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < MAX_BITS; i++) {
        if (find(set, i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B, C;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);
    printf("A = "); 
    display(A);  

    initialize(&B);
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("B = "); 
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

    deleteElem(&A, 6);
    printf("A after deleting 6 = "); 
    display(A); 

    return 0;
}
