class Solution {
    // dp[i]存储以i为结尾的单词的起始位置
    vector<vector<int>> dp;
    vector<string> result;
    
    // 对于字符串s，以index为起点，在合法单词终点处填入index（更新dp）
    void check(string s, int index, vector<string> wordDict){
        for (int i = 0; i < wordDict.size(); i++){
            string temp = s.substr(index, wordDict[i].size());
            if (temp == wordDict[i]){
                dp[index + wordDict[i].size() - 1].push_back(index);
            }
        }
    }
    
    // 根据dp内容回溯递归生成结果
    void get_result(string temp, int index){
        for (auto i : dp[index]){
            // 得到一个合法结果
            if (i == 0){
                result.push_back(temp);
                continue;
            }
            // 回溯
            temp.insert(i, " ");
            get_result(temp, i-1);
            temp.erase(temp.begin()+i, temp.begin()+i+1);
        }
    }
    
public:
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dp = vector<vector<int>>(s.size(), vector<int>());
        for (int i = 0; i < s.size(); i++){
            // 上一位是一个单词的结尾
            if (i == 0 || dp[i - 1].size() > 0){
                check(s, i, wordDict);
            }
        }
        // 有一个或多个合法结果
        if (dp.back().size() > 0){
            get_result(s, int(s.size()) - 1);
        }
        return result;
    }
};