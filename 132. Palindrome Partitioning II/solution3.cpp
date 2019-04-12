// data[i][j]: 表示i~j为回文序列
// dp[k]: 表示从起始位置到第k个字符最少划分次数


class Solution {
    
public:
    int minCut(string s) {
        // 初始化dp数组
        vector<vector<int>> data(s.size(), vector<int>(s.size(), 0));
        vector<int> dp(s.size() + 1, 0);
        for (int i = 0; i < dp.size(); i++){
            dp[i] = i - 1;
        }

        // 动态规划
        for (int end = 0; end < s.size(); end++){
            for (int begin = 0; begin <= end; begin++){
                // begin+1 > end-1 ： 表示begin和end相邻或相同
                if (s[begin] == s[end] && (begin+1 > end-1 || data[begin+1][end-1])){
                    dp[end+1] = min(dp[end+1], dp[begin] + 1);
                    data[begin][end] = 1;
                }
            }
        }
        
        return dp.back();
    }
};