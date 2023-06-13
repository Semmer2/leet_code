#include <stdio.h>
#include <malloc.h>
#include <string.h>

void dfs(int** isConnected, int* count, int cityNum, int citySize, int** cityFlag) {
    if(!(*cityFlag)[cityNum]) (*count)++;
    (*cityFlag)[cityNum] = (*count);
    for(int i = 0; i < citySize; i++) {
        if(isConnected[cityNum][i] && !(*cityFlag)[i]) {
            (*cityFlag)[i] = (*count);
            dfs(isConnected, count, i, citySize, cityFlag);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* cityFlag = (int*)malloc(isConnectedSize * sizeof(int));
    memset(cityFlag, 0, isConnectedSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        dfs(isConnected, &count, i, isConnectedSize, &cityFlag);
    }
    return count;
}

int main() {
    int city = 4;
    int** isConnected = (int**)malloc(city * sizeof(int*));
    int city1[] = {1,0,0,1};
    int city2[] = {0,1,1,0};
    int city3[] = {0,1,1,1};
    int city4[] = {1,0,1,1};
    isConnected[0] = city1;
    isConnected[1] = city2;
    isConnected[2] = city3;
    isConnected[3] = city4;
    findCircleNum(isConnected, city, NULL);
    return 0;
}