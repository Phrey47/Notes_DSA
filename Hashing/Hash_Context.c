#include <stdio.h>
#include <math.h>
#include <ctype.h>

//example
int hashHundredths(float num) {
    if(num < 0) num = -num;
    int hundredths = ((int)roundf(num * 100)) % 10;
    return hundredths;
}

int hashName(char *name){
    char first = toupper(name[0]);
    if(first >= 'A' && first <= 'Z'){
        return first - 'A';
    } else{
        return -1;
    }
}

int hashRgb(int r, int g, int b) {
    return (r * 3 + g * 5 + b * 7) % 64;
}

int main() {
    float number = 45.67;
    int hashValue = hashHundredths(number);
    printf("Hash (hundredths of %.2f): %d\n\n", number, hashValue);

    printf("A = %d\n", hashName("Anderson"));
    printf("B = %d\n", hashName("Brown"));
    printf("Z = %d\n", hashName("Zelda"));

    printf("\n");
    printf("%d\n", hashRgb(255, 0, 0));
    printf("%d\n", hashRgb(0, 255, 0));
    printf("%d\n", hashRgb(0, 0, 255));
    printf("%d\n", hashRgb(123, 200, 45));

    return 0;
}




