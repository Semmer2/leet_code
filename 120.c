#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int* ans = (int*)malloc(triangleSize * sizeof(int));
    int min_val, prev, now;
    memset(ans, 0, triangleSize * sizeof(int));
    ans[0] = triangle[0][0];
    min_val = triangleSize == 1 ? ans[0] : INT_MAX;
    prev = ans[0];
    if(triangleSize >= 2) {
        ans[0] = prev + triangle[1][0];
        ans[1] = prev + triangle[1][1];
        if(triangleSize == 2)
            min_val = MIN(ans[0], ans[1]);
        prev = ans[0];
    }
    for(int row = 2; row < triangleSize; row++) {
        for(int col = 0; col <= row; col++) {
            if(col > 0 && col < row){
                now = MIN(prev + triangle[row][col], ans[col] + triangle[row][col]);
                prev = ans[col];
            } else if (col == 0) {
                now = ans[col] + triangle[row][col];
                //prev = ans[col];
            } else {
                now = prev + triangle[row][col];
                prev = ans[0];
            }
            ans[col] = now;
            if (row == triangleSize - 1)
            {
                min_val = MIN(min_val, now);
            }
        }
    }
    return min_val;
}

int main() {
    int tri_1[] = {2};
    int tri_2[] = {3, 4};
    int tri_3[] = {5, 6, 7};
    int tri_4[] = {4, 1, 8, 3};
    int* tri[] = {tri_1, tri_2, tri_3, tri_4};
    minimumTotal(tri, 4, NULL);
    return 0;
}