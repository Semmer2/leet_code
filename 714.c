#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee) {
    int* dp[pricesSize + 1], maxPf = 0;
    if(pricesSize == 1) {
        return 0;
    } else if(pricesSize == 2) {
        return MAX(0, prices[1] - prices[0] - fee);
    }

    //pricesSize >= 3
    for(int i = 0; i < pricesSize; i++) {
        dp[i] = (int*)malloc((pricesSize + 1) * sizeof(int));
        memset(dp[i], 0, (pricesSize + 1) * sizeof(int));
    }
    for(int i = 2; i <= pricesSize; i++) {
        dp[1][i] = MAX(dp[1][i - 1], prices[i - 1] - prices[0] - fee);
    }
    for(int i = 2; i < pricesSize; i++) {
        for(int j = i + 1; j <= pricesSize; j++) {
            dp[i][j] = MAX(dp[i - 2][i - 1] + prices[j - 1] - prices[i - 1] - fee, MAX(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    maxPf = dp[pricesSize - 1][pricesSize];
    for(int i = 0; i <= pricesSize; i++) {
        free(dp[i]);
    }
    return maxPf;
}

int main() {
    int prices[] = {4,5,2,4,3,3,1,2,5,4};
    maxProfit(prices, 10, 1);
    return 0;
}