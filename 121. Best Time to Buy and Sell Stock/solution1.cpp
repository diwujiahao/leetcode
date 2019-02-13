// 动态规划
// dp[i]表示第i天买入可得到的的最大收益
// 配合 the_hightest_price （表示i之后的股票最高价）计算

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }
        int the_hightest_price = prices[prices.size() - 1];
        int result = 0;
        vector<int> dp = vector<int>(prices.size());
        for (int i = prices.size() - 2; i >= 0; i--){
            dp[i] = the_hightest_price - prices[i];
            result = (dp[i] > result) ? dp[i] : result;
            the_hightest_price = (prices[i] > the_hightest_price) ? prices[i] : the_hightest_price;
        }
        return result;
    }
};