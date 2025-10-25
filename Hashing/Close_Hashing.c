#include <stdio.h>

int hash(char code[]) {
    return ((code[0] - 'A') * 26 * 26 +
            (code[1] - 'A') * 26 +
            (code[2] - 'A')) % 10;
}

int main() {
    char *A[] = {
        "JFK", "LAX", "SFO", "CDG", "LHR", "NRT",
        "ATL", "DXB", "PEK", "MIA", "SYD", "ORD"
    };
    int length = sizeof(A) / sizeof(A[0]);
    int i;

    for (i = 0; i < length; i++) {
        printf("Index %d - %d\n", i, hash(A[i]));
    }
}



// Set A ={"JFK", "LAX", "SFO", "CDG", "LHR", "NRT", "ATL", "DXB", "PEK", "MIA", "SYD", "ORD"}

// hash(code) == ((cod[o] - 'A') * 26 * 26 + (code[1] - 'A') * 26 + (code[2] - 'A')) % 10

// Example:
// hash("JFK") -> 4;