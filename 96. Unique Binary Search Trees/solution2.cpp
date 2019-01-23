class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++){
            for (int index = 0; index < i; index++){
                dp[i] += dp[index] * dp[i-index-1];
            }
        }
        return dp.back();
    }
};
