// 超时

class Solution {
    vector<vector<int>> data_in; // 保存入度
    vector<vector<int>> data_out; // 保存出度
    
    bool check(vector<vector<int>> &matrix, int i, int j){
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()){
            return false;
        }
        return true;
    }
    
    int find_path(vector<vector<int>> &matrix, int i, int j){
        if (data_out[i][j] == 0){
            return 1;
        }
        int temp = 0;
        
        if (check(matrix, i-1, j)){
            if (matrix[i-1][j] > matrix[i][j]){
                temp = max(temp, find_path(matrix, i-1, j) + 1);
            }
        }
        if (check(matrix, i+1, j)){
            if (matrix[i+1][j] > matrix[i][j]){
                temp = max(temp, find_path(matrix, i+1, j) + 1);
            }
        }
        if (check(matrix, i, j-1)){
            if (matrix[i][j-1] > matrix[i][j]){
                temp = max(temp, find_path(matrix, i, j-1) + 1);
            }
        }
        if (check(matrix, i, j+1)){
            if (matrix[i][j+1] > matrix[i][j]){
                temp = max(temp, find_path(matrix, i, j+1) + 1);
            }
        }
        
        
        
        return temp;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        
        data_in = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        data_out = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                
                if (check(matrix, i-1, j)){
                    if (matrix[i-1][j] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                    else if (matrix[i-1][j] > matrix[i][j]){
                        data_out[i][j]++;
                    }
                }
                if (check(matrix, i+1, j)){
                    if (matrix[i+1][j] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                    else if (matrix[i+1][j] > matrix[i][j]){
                        data_out[i][j]++;
                    }
                }
                if (check(matrix, i, j-1)){
                    if (matrix[i][j-1] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                    else if (matrix[i][j-1] > matrix[i][j]){
                        data_out[i][j]++;
                    }
                }
                if (check(matrix, i, j+1)){
                    if (matrix[i][j+1] < matrix[i][j]){
                        data_in[i][j]++;
                    }
                    else if (matrix[i][j+1] > matrix[i][j]){
                        data_out[i][j]++;
                    }
                }
                
            }
        }
        
        int result = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (data_in[i][j] == 0){
                    result = max(result, find_path(matrix, i, j));
                }
            }
        }
        
        return result;
    }
};
