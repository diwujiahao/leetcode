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
    void begin(vector<vector<int>> &matrix, int i, int j){
        recursion(matrix, i - 1, j, matrix[i][j], dp[i][j]);
        recursion(matrix, i + 1, j, matrix[i][j], dp[i][j]);
        recursion(matrix, i, j - 1, matrix[i][j], dp[i][j]);
        recursion(matrix, i, j + 1, matrix[i][j], dp[i][j]);
    }
    
    // 检查是否更新
    void recursion(vector<vector<int>> &matrix, int i, int j, int last_num, int last_dp){
        // 检查[i][j]范围
        if (!check_range(matrix, i, j)){
            return;
        }
        // 检查是否递增
        if (matrix[i][j] <= last_num){
            return;
        }
        // 检查是否需要更新
        if (dp[i][j] > last_dp){
            return;
        }
        // 进行更新
        dp[i][j] = last_dp + 1;
        result = max(result, dp[i][j]);
        begin(matrix, i, j);
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        data_in = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 1));
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                
                if (check_range(matrix, i-1, j)){
                    if (matrix[i-1][j] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                }
                if (check_range(matrix, i+1, j)){
                    if (matrix[i+1][j] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                }
                if (check_range(matrix, i, j-1)){
                    if (matrix[i][j-1] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                }
                if (check_range(matrix, i, j+1)){
                    if (matrix[i][j+1] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (data_in[i][j] == 0){
                    begin(matrix, i, j);
                }
            }
        }
        return result;
    }
};
