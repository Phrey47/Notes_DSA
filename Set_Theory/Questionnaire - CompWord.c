#include <stdio.h>
#include <stdbool.h>

// write your functions here...
void setAnswer(CompWord* profile, int index, int value){
    if(index >= 0 && index < 10){
        if(value){
            *profile |= 1 << index;
        }
    }
}

int getAnswer(CompWord profile, int index){
    return (profile >> index) & 1;
}

int countYesAnswers(CompWord profile){
    int i, count = 0;
    
    for(i = 0;i < 10;i++){
        if((profile >> i) & 1 == 1){
            count++;
        }
    }
    
    return count;
}

void printAnswers(CompWord profile){
    int i;
    
    for(i = 9;i >= 0;i--){
        printf("%d", (profile >> i) & 1);
    }
    
    printf("\n");
}

int compareProfiles(CompWord a, CompWord b){
    int i, count = 0;
    
    for(i = 0;i < 10;i++){
        if(((a >> i) & 1) == ((b >> i) & 1)){
            count++;
        }
    }
    return count;
}

CompWord unionProfiles(CompWord a, CompWord b){
    return a | b;
}

CompWord intersectProfiles(CompWord a, CompWord b){
    return a & b;
}

CompWord differenceProfiles(CompWord a, CompWord b){
    return a & (~b);
}
