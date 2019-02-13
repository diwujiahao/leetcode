// 动态规划
// buy1，buy2，sell1，sell2分别表示四次操作有的现有资金

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }
        int buy1 = -prices[0], buy2 = -prices[0], sell1 = 0, sell2 = 0;
        for (int i = 1; i < prices.size(); i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};