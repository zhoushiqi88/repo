class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int maxn = m > n ? m:n;
        vector<vector<int>> dp(m+1,vector<int>(n+1,maxn+1));
        for(int i = 0;i <= m;i++) dp[i][0] = i;
        for(int j = 0;j <= n;j++) dp[0][j] = j;
        for(int i = 1;i <=m;i++) {
            for(int j = 1;j <= n;j++) {
                if(word1[i-1] != word2[j-1]) {
                    int min = dp[i-1][j-1] < dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
                    min = min < dp[i][j-1] ? min : dp[i][j-1];
                    dp[i][j] = min+1;
                }
                else {
                    int min = dp[i][j-1] < dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
                    min = (min+1) < dp[i-1][j-1] ? (min+1) : dp[i-1][j-1];
                    dp[i][j] = min;
                }
            }
        }
        return dp[m][n];
    }
};