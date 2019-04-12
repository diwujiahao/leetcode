class Solution {
    vector<vector<bool>> dp;
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<bool>>(s.size()+1, vector<bool>(p.size()+1, false));
        // 初始化
        dp[0][0] = true;
        for (int j = 1; j < dp[0].size(); j++){
            // 只有当s为空，p利用*为空时，可能出现true
            if (p[j-1] == '*' && dp[0][j-2]) {
                dp[0][j] = true;
            }
        }
        
        // 动态规划
        for (int i = 1; i < dp.size(); i++){
            for (int j = 1; j < dp[i].size(); j++){
                // 当前匹配成功-当前状态取决于之前状态
                if (p[j-1] == s[i-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                // 当前出现*
                else if (p[j-1] == '*'){
                    // *前字符与当前字符一致-当前字符为重复字符
                    if (p[j-2] == s[i-1] || p[j-2] == '.'){
                        // 分别对应重复多次，重复一次，重复零次
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }
                    // *前字符与当前字符 不 一致
                    else if (p[j-2] != s[i-1]){
                        // 星号作用为重复零次
                        dp[i][j] = (j-2 > 0) ? dp[i][j-2] : false;
                    }
                }
                
            }
        }
        
        return dp.back().back();
    }
};
