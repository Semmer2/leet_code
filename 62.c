#include <stdio.h>
#include <malloc.h>
#include <string.h>

int uniquePaths(int m, int n){
    int* roadMap[m];
    int ret = 0;
    if(m == 1 || n == 1)return 1;

    for(int i = 0; i < m; i++) {
        roadMap[i] = (int*)malloc(n * sizeof(int));
        memset(roadMap[i], 0, n * sizeof(int));
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0) {
                roadMap[i][j] = 1;
            } else {
                roadMap[i][j] = roadMap[i][j - 1] + roadMap[i - 1][j];
            }
        }
    }
    ret = roadMap[m - 1][n - 1];
    for(int i = 0; i < m; i++) {
        free(roadMap[i]);
    }
    return ret;
}

int main() {
    uniquePaths(3, 7);
    return 0;
}