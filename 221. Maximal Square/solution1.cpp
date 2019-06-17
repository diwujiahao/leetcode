class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int result = 0;
        
        // 动态规划
        for (int i = 1; i <= matrix.size(); i++){
            for (int j = 1; j <= matrix[0].size(); j++){
                // 当前位置为0
                if (matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }
                // 当前位置为1
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        
        return pow(result, 2);
    }
};