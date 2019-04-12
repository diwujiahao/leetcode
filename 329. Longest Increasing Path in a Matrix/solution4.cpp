// 动态规划

class Solution {
    
    vector<vector<int>> data_in; // 保存入度
    vector<vector<int>> dp;
    int result = 1;
    
    bool check_range(vector<vector<int>> &matrix, int i, int j){
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()){
            return false;
        }
        return true;
    }
    
    // 分发函数
    int begin(vector<vector<int>> &matrix, int i, int j){
        int temp = 0;
        temp = max(temp, recursion(matrix, i - 1, j, matrix[i][j]));
        temp = max(temp, recursion(matrix, i + 1, j, matrix[i][j]));
        temp = max(temp, recursion(matrix, i, j - 1, matrix[i][j]));
        temp = max(temp, recursion(matrix, i, j + 1, matrix[i][j]));
        return temp + 1;
    }
    
    // 检查是否更新
    int recursion(vector<vector<int>> &matrix, int i, int j, int last_num){
        // 检查[i][j]范围
        if (!check_range(matrix, i, j)){
            return 0;
        }
        // 检查是否递增
        if (matrix[i][j] <= last_num){
            return 0;
        }
        // 检查是否需要更新
        if (dp[i][j] != 0){
            return dp[i][j];
        }
        // 进行更新
        dp[i][j] = begin(matrix, i, j);
        return dp[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                result = max(result, begin(matrix, i, j));
            }
        }
        return result;
    }
};