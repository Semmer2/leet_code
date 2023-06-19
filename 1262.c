#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSumDivThree(int* nums, int numsSize) {
    int remains[3] = {0}, remain = 0;
    int curr[3] = {0};
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < 3; j++) {
            remain = (remains[j] + nums[i]) % 3;
            curr[remain] = MAX(curr[remain], remains[j] + nums[i]);
        }
        remains[0] = MAX(curr[0], remains[0]);
        remains[1] = MAX(curr[1], remains[1]);
        remains[2] = MAX(curr[2], remains[2]);
        curr[0] = curr[1] = curr[2] = 0;
    }
    return remains[0];
}

int main() {
    int nums[] = {3,6,5,1,8};
    maxSumDivThree(nums, 5);
    return 0;
}