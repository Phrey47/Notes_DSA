#include <stdio.h>
#include <math.h>

//example
int hashHundredths(float num) {
    return ((int)round(num * 100)) % 10;
}

int main() {
    float number = 45.67;
    int hashValue = hashHundredths(number);
    printf("Hash (hundredths of %.2f): %d\n", number, hashValue); 
    return 0;
}
