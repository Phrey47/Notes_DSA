#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS 8   // since we're using unsigned char (8 bits)

void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        *set |= (1 << element);
    }
}

void deleteElem(unsigned char *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        return (set & (1 << element)) != 0;
    }
    return false;
}

// Union
unsigned char set_union(unsigned char A, unsigned char B) {
    return A | B;
}

// Intersection
unsigned char set_intersection(unsigned char A, unsigned char B) {
    return A & B;
}

// Difference (A - B)
unsigned char set_difference(unsigned char A, unsigned char B) {
    return A & ~B;
}

void display(unsigned char set) {
    printf("{ ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (find(set, i)) {
            printf("%d ", i);
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

    C = set_union(A, B);
    printf("A ∪ B = "); 
    display(C); 

    C = set_intersection(A, B);
    printf("A ∩ B = "); 
    display(C); 

    C = set_difference(A, B);
    printf("A - B = "); 
    display(C); 

    deleteElem(&A, 6);
    printf("A after deleting 6 = "); 
    display(A); 

    printf("Example Output\n");

    return 0;
}
