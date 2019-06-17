class Solution {
    pair<int, int> left;
    pair<int, int> right;
    
    bool judge(vector<vector<int>>& matrix, int target){
        for (int i = left.first; i <= right.first; i++){
            int j = left.second;
            if (matrix[i][j] == target){
                return true;
            }
            if (matrix[i][j] > target){
                right.first = i - 1;
                break;
            }
        }
        for (int j = left.second; j <= right.second; j++){
            int i = left.first;
            if (matrix[i][j] == target){
                return true;
            }
            if (matrix[i][j] > target){
                right.second = j - 1;
                break;
            }
        }
        left.first++;
        left.second++;
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        left = make_pair(0, 0);
        right = make_pair(matrix.size()-1, matrix[0].size()-1);
        while(!(left.first > right.first || left.second > right.second)){
            if (judge(matrix, target)){
                return true;
            }
        }
        return false;
    }
};