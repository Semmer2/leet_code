#include <stdio.h>

inline int max(int e1, int e2);
int max(int e1, int e2) {
    return  e1 > e2 ? e1 : e2;
}

int longestOnes(int* nums, int numsSize, int k) {
    int continuousOnes = 0, count = 0;
    int start = 0, available_flip = k;
    //get pos of first one
    for(int i = 0, j = 0; j < numsSize; j++) {
        if(nums[j]) {
            count++;
        } else {
            //zero
            if (available_flip) {
                count++;
                available_flip--;
            } else {
                continuousOnes = max(continuousOnes, count);
                //zero but no flip chance
                for(; i < j; i++) {
                    if(nums[i]) {
                        count--;
                    }
                    if(!nums[i]) {
                        if(k) {
                            i++;
                        } else {
                            count = 0;
                            i = j + 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    continuousOnes = max(continuousOnes, count);
    return continuousOnes;
}

int main() {
    int nums[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    longestOnes(nums, 19, 0);
    return 0;
}