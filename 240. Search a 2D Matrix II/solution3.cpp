// 从左下角/右上角出发

class Solution {   
   
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int i = int(matrix.size()) - 1, j = 0;
        while(i >= 0 && j < matrix[0].size()){
            if (matrix[i][j] == target){
                return true;
            }
            (matrix[i][j] < target) ? j++ : i--;
        }
        return false;
    }
};