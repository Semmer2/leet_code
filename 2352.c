#include <stdio.h>
#include <stdbool.h>

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int pairs = 0;
    bool flag = true;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            for(int k = 0; k < gridSize; k++) {
                if(grid[i][k] != grid[k][j]) {
                    //printf("(i,k): %d, %d; (k, j): %d, %d\n", i, k, k, j);
                    flag = false;
                    break;
                }
            }
            if(flag) pairs++;
            flag = true;
            //printf("compare\n");
        }
    }
    return pairs;
}

int main() {
    int grid1[] = {3,1,2,2};
    int grid2[] = {1,4,4,5};
    int grid3[] = {2,4,2,2};
    int grid4[] = {2,4,2,2};

    int* grid[] = {grid1,grid2,grid3,grid4};
    equalPairs(grid, 4, NULL);
    return 0;
}