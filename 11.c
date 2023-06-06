#include <stdio.h>

int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

int min(int e1, int e2) {
    return e1 > e2 ? e2 : e1;
}

int maxArea(int* height, int heightSize) {
    int start = 0, end = heightSize - 1, max_vol = 0;
    int cur_vol = 0;
    if(heightSize == 1) return 0;
    if(heightSize == 2) return min(height[0], height[1]) * 1;
    while(start < end) {
        cur_vol = min(height[start], height[end]) * (end - start);
        max_vol = max(cur_vol, max_vol);
        height[start] > height[end] ? end-- : start++;
    }
    return max_vol;
}

int main() {
    int height[9] = {1,8,6,2,5,4,8,3,7};
    maxArea(height, 9);
    return 0;
}