#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isInterleave(char * s1, char * s2, char * s3){
    unsigned char len1 = (unsigned char)strlen(s1);
    unsigned char len2 = (unsigned char)strlen(s2);
    unsigned char len3 = (unsigned char)strlen(s3);
    char dp[len1 + 1][len2 + 1];
    if(len1 + len2 != len3)
        return false;
    memset(dp, 0, (len1 + 1) * (len2 + 1) * sizeof(unsigned char));
    dp[0][0] = 1;
    for (unsigned char i = 1; i <= len1; i++) {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    for (unsigned char i = 1; i <= len2; i++) {
        dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for(unsigned char i = 1; i <= len1; i++) {
        for(unsigned char j = 1; j <= len2; j++) {
            if(s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == 1) {
                dp[i][j] = 1;
            } else if(s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == 1) {
                dp[i][j] = 1;
            }
        }
    }
    if(dp[len1][len2] == 1) return true;
    return false;
}
 
int main() {
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";
    isInterleave(s1, s2, s3);
    return 0;
}