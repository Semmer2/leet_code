#include <stdio.h>
#include <stdbool.h>

#define OFFSET 1000
#define ARR_MAX_LEN 2001

inline int max(int e1, int e2);
int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

bool uniqueOccurrences(int* arr, int arrSize) {
    int frequence[ARR_MAX_LEN] = {0};
    int arrMax = -1000;
    for (int i = 0; i < arrSize; i++) {
        frequence[arr[i] + OFFSET]++;
        arrMax = max(arrMax, arr[i]);
    }

    bool freqArr[ARR_MAX_LEN] = {false};
    for (int i = 0; i < ARR_MAX_LEN; i++) {
        if(frequence[i] && !freqArr[frequence[i]]) {
            freqArr[frequence[i]] = true;
        } else if(frequence[i] && freqArr[frequence[i]]){
            return false;
        }
    }

    return true;
}

int main() {
    int arr[]={1,2,2,1,1,3};
    uniqueOccurrences(arr, 6);
    return 0;
}