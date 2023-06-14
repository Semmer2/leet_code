#include <stdio.h>
#include <malloc.h>

inline int max(int e1, int e2);

int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

int rob(int* nums, int numsSize) {
    int robTotal[numsSize];
    robTotal[0] = nums[0];
    if(numsSize == 1) {
        return robTotal[0];
    }
    robTotal[1] = max(nums[0], nums[1]);
    if(numsSize == 2) {
        return robTotal[1];
    }
    for (int i = 2; i < numsSize; i++)
    {
        robTotal[i] = max(robTotal[i - 1], robTotal[i - 2] + nums[i]);
    }
    return robTotal[numsSize - 1];
}

int main() {
    int nums[] = {2,7,9,3,1};
    rob(nums, 5);
    return 0;
}