#include <stdio.h>

int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}
//what if it is not continuous?
double findMaxAverage(int* nums, int numsSize, int k) {
    int result = 0;
    int i = 0, total = 0;
    for (int i = 0; i < k; i++) {
        total += nums[i];
    }
    result = total;
    while(i < numsSize - k) {
        total = total - nums[i] + nums[i + k];

        if (nums[i] < nums[i + k])
            result = max(total, result);
        i++;
    }
    return (double)(result / (k * 1.0));
}

int main() {
    int nums[1] = {5};
    findMaxAverage(nums, 1, 1);
    return 0;
}