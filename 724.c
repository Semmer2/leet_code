#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
    int index = -1;
    int left = 0, right = 0;
    for (int i = 1; i < numsSize; i++) {
        right += nums[i];
    }
    if (!right) return 0;
    for (int i = 1; i < numsSize; i++) {
        if(right - nums[i] == left + nums[i - 1]) {
            index = i;
            break;
        }
        right -= nums[i];
        left += nums[i - 1];
    }
    return index;
}

int main() {
    int nums[] = {1,7,3,6,5,6};
    pivotIndex(nums, 6);
    return 0;
}