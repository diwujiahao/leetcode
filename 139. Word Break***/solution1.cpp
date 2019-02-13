// 动态规划
class Solution {
    // dp[i]表示s[i]为结尾的子串是否是一个字典中的单词
    vector<bool> dp;
    
    // 对于字符串s，从index位开始，将完全匹配单词的结尾位置在dp中标记为true
    void check(string s, int index, vector<string> wordDict){
        for (int i = 0; i < wordDict.size(); i++){
            string temp = s.substr(index, wordDict[i].size());
            if (temp == wordDict[i]){
                dp[index + wordDict[i].size() - 1] = true;
            }
        }
    }
    
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<bool>(s.size(), false);
        for (int i = 0; i < s.size(); i++){
            // 上一位是一个单词的结尾
            if (i == 0 || dp[i - 1]){
                check(s, i, wordDict);
            }
        }
        return dp.back();
    }
};