#include <stdio.h>
#include <malloc.h>
#include <string.h>

inline int min(int e1, int e2);

int min(int e1, int e2) {
    return e1 > e2 ? e2 : e1;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int* stairFee = (int*)malloc(costSize * sizeof(int));
    int finalCost = 0;
    memset(stairFee, 0, costSize * sizeof(int));
    if(costSize < 2) return 0;
    for(int i = 2; i < costSize; i++) {
        stairFee[i] = min(stairFee[i - 1] + cost[i - 1], stairFee[i - 2] + cost[i - 2]);
    }
    finalCost = min(stairFee[costSize - 1] + cost[costSize - 1], stairFee[costSize - 2] + cost[costSize - 2]);
    return finalCost;
}

int main() {
    int cost[] = {1,100,1,1,1,100,1,1,100,1};
    minCostClimbingStairs(cost, 10);
    return 0;
}
