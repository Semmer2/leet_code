#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*bad solution
int maxProfit(int* prices, int pricesSize, int fee) {
    int* dp[pricesSize], maxPf = 0;
    if(pricesSize == 1) {
        return 0;
    } else if(pricesSize == 2) {
        return MAX(0, prices[1] - prices[0] - fee);
    }

    //pricesSize >= 3
    for(int i = 0; i < pricesSize; i++) {
        dp[i] = (int*)malloc((pricesSize + 2 - i) * sizeof(int));
        memset(dp[i], 0, (pricesSize + 2 - i) * sizeof(int));
    }
    for(int i = 2; i <= pricesSize; i++) {
        dp[1][i] = MAX(dp[1][i - 1], prices[i - 1] - prices[0] - fee);
    }
    for(int i = 2; i < pricesSize; i++) {
        for(int j = i + 1; j <= pricesSize; j++) {
            dp[i][j - i + 1] = MAX(dp[i - 2][2] + prices[j - 1] - prices[i - 1] - fee, MAX(dp[i - 1][j - i + 2], dp[i][j - i]));
        }
    }
    maxPf = dp[pricesSize - 1][2];
    for(int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }
    return maxPf;
}
*/
int maxProfit(int* prices, int pricesSize, int fee) {
    int pft = 0;
    int* dp[2];
    if(pricesSize == 1) {
        return 0;
    }

    for(int i = 0; i < 2; i++) {
        dp[i] = (int*)malloc(pricesSize * sizeof(int));
        memset(dp[i], 0, pricesSize * sizeof(int));
    }
    dp[0][0] = 0;
    dp[1][0] = -prices[0];
    for(int i = 1; i < pricesSize; i++) {
        dp[0][i] = MAX(dp[0][i - 1], prices[i] + dp[1][i - 1] - fee);
        dp[1][i] = MAX(dp[1][i - 1], dp[0][i - 1] - prices[i]);
    }
    pft = dp[0][pricesSize - 1];
    for(int i = 0; i < 2; i++) {
        free(dp[i]);
    }
    return pft;
}

int main() {
    //int prices[] = {4,5,2,4,3,3,1,2,5,4};
    int prices[] = {1, 3, 2, 8, 4, 9};
    maxProfit(prices, 6, 3);
    return 0;
}