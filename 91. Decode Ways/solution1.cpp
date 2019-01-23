class Solution {
    // 检查本位能否单独组成编码
    bool check1(string s, int index){
        if (s[index] == '0'){
            return false;
        }
        return true;
    }
    // 检查本位和上一位能否组成两位编码
    bool check2(string s, int index){
        if (s[index-1] == '2' && s[index] - '0' <= 6){
            return true;
        }
        else if (s[index-1] == '1'){
            return true;
        }
        return false;
    }
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 0;
        }
        // 初始化动态规划数组
        // dp[i]表示到第i个元素为止，划分方法的个数
        vector<int> dp(s.size(), 0);
        dp[0] = (s[0] == '0') ? 0 : 1;
        // 开始循环动态规划
        for (int i = 1; i < s.size(); i++){
            // 两种组合方式都可以
            if (check1(s, i) && check2(s, i)){
                dp[i] = (i > 1) ? dp[i-1] + dp[i-2] : dp[i-1] + 1;
            }
            // 只能本位编码
            else if (check1(s, i)){
                dp[i] = dp[i-1];
            }
            // 只能本位和上一位双位编码（10/20）
            else if (check2(s, i)){
                dp[i] = (i > 1) ? dp[i-2] : 1;
            }
            // 无法编码（70）
            else{
                dp[i] = 0;
            }
        }
        return dp.back();
    }
};