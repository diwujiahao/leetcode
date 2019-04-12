// 动态规划
// 实际check函数做了很多重复计算，记录下来可以省时间

class Solution {
    
    bool check(string s, int begin, int end){
        while(begin < end){
            if (s[begin++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
public:
    int minCut(string s) {
        
        // 初始化dp数组
        vector<int> dp(s.size() + 1, 0);
        for (int i = 0; i < dp.size(); i++){
            dp[i] = i - 1;
        }
        
        // 动态规划
        for (int end = 0; end < s.size(); end++){
            for (int begin = 0; begin <= end; begin++){
                if (check(s, begin, end)){
                    dp[end+1] = min(dp[end+1], dp[begin] + 1);
                }
            }
        }
        
        return dp.back();
    }
};