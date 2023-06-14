#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for(int i = 0; i < numsSize; i++) {
        ret = ret ^ nums[i];
    }
    return ret;
}

int main() {
    int nums[] = {4,1,2,1,2};
    singleNumber(nums, 5);
    return 0;
}