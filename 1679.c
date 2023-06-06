#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int cmp(const void* n1, const void* n2) {
    return *(int *)n1 - *(int *)n2;
}

int maxOperations(int* nums, int numsSize, int k) {
    int gap = 0, op_num = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0, j = numsSize - 1; i < j;) {
        if(nums[i] >= k) break;
        if(nums[i] + nums[j] == k) {
            op_num++;
            j--;
            i++;
            continue;
        }
        else if(nums[i] + nums[j] > k) {
            j--;
            continue;
        } else {
            i++;
        }
    }
    return op_num;
}

int main() {
    int nums[18] = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    maxOperations(nums, 18, 2);
    return 0;
}