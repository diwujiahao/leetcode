class Solution {
    vector<vector<int>> data;
public:
    int minDistance(string word1, string word2) {
        // 初始化dp数组
        data = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        for (int i = 0; i <= word1.size(); i++){
            data[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++){
            data[0][j] = j;
        }
        // 动态规划
        for (int i = 1; i <= word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++){
                int temp = (word1[i-1] == word2[j-1]) ? 0 : 1 ;
                data[i][j] = min(min(data[i-1][j] + 1, data[i][j-1] + 1), data[i-1][j-1] + temp);
            }
        }
        return data.back().back();
    }
};