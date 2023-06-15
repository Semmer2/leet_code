#include <stdio.h>
#include <string.h>
#include <malloc.h>

inline int max(int e1, int e2);
int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

int longestCommonSubsequence(char* text1, char* text2) {
    int count = 0;
    int t_len1 = strlen(text1), t_len2 = strlen(text2);
    int* dp[t_len1 + 1];
    for(int i = 0; i <= t_len1; i++) {
        dp[i] = (int*)malloc((t_len2 + 1) * sizeof(int));
        memset(dp[i], 0, (t_len2 + 1) * sizeof(int));
    }

    for(int i = 1; i <= t_len1; i++) {
        for(int j = 1; j <= t_len2; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    count = dp[t_len1][t_len2];
    for(int i = 0; i <= t_len1; i++) {
        free(dp[i]);
    }
    return count;
}

int main() {
    char* text1 = "abcde",* text2 = "ace";
    longestCommonSubsequence(text1, text2);
    return 0;
}