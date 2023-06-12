#include <stdio.h>

inline int max(int e1, int e2);
int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

int longestSubarray(int* nums, int numsSize) {
    int longestOnes = 0, count = 0, delete = 1;
    int start = 0, end = 0;
    for (; end < numsSize; end++) {
        if(nums[end]) {
            count++;
        } else {
            if(delete) {
                delete--;
            } else {
                longestOnes = max(longestOnes, count);
                for(; start < end; start++) {
                    if(nums[start]) {
                        count--;
                    } else {
                        start++;
                        break;
                    }
                }
            }
        }
    }
    longestOnes = max(longestOnes, count);
    if(delete) longestOnes--;
    return longestOnes;
}

int main() {
    int nums[] = {1,1,0,1};
    longestSubarray(nums, 4);
    return 0;
}