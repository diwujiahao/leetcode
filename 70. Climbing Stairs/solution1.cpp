//动态规划
class Solution {
public:
    int climbStairs(int n) {
        //特殊情况判断
        if (n < 3){
            return n;
        }
        //初始化
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        //动态规划更新
        for (int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};