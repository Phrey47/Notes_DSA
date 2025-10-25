#include <stdio.h>
#include <stdbool.h>

// write your funcitons here...
void setAnswer(BitVect* profile, int index, int value){
    if(index >= 0 && index < 10){
        profile->answers[index] = value;
    }
}

int getAnswer(BitVect profile, int index){
    int i;
    
    for(i = 0;i < 10;i++){
        if(i == index){
            return profile.answers[i];
        }
    }
    
    return -1;
}

int countYesAnswers(BitVect profile){
    int i, count = 0;
    
    for(i = 0;i < 10;i++){
        if(profile.answers[i] == 1){
            count++;
        }
    }
    
    return count;
}

void printAnswers(BitVect profile){
    int i;
    
    for(i = 9;i >= 0;i--){
        printf("%d", profile.answers[i]);
    }
    
    printf("\n");
}

int compareProfiles(BitVect a, BitVect b){
    int i, j, count = 0;
    
    for(i = 0;i < 10;i++){
        if(a.answers[i] == b.answers[i]){
            count++;
        }
    }
    
    return count;
}

BitVect unionProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    int i;
    
    for(i = 0;i < 10;i++){
        c.answers[i] = a.answers[i] | b.answers[i];
    }
    
    return c;
}

BitVect intersectProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    int i, j;
    
    for(i = 0;i < 10;i++){
       c.answers[i] = a.answers[i] & b.answers[i]; 
    }
    
    return c;
}

BitVect differenceProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    int i, j;
    
    for(i = 0;i < 10;i++){
        c.answers[i] = a.answers[i] & (~b.answers[i]);
    }
    
    return c;
}
