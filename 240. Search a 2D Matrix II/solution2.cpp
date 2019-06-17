class Solution {
    
    bool find_matrix(vector<vector<int>>& matrix,pair<int, int> left, pair<int, int> right, int target){
        // 两个顶点重合
        if (left.first > right.first || left.second > right.second){
            return false;
        }
        // 顶点不重合
        int index;
        for (index = 0; index <= min(right.first-left.first, right.second-left.second);){
            if (matrix[left.first+index][left.second+index] == target){
                return true;
            }
            else if (matrix[left.first+index][left.second+index] < target){
                index++;
            }
            else{
                break;
            }
        }
        return find_matrix(matrix, make_pair(left.first+index, left.second), make_pair(right.first, left.second+index-1), target) || find_matrix(matrix, make_pair(left.first, left.second+index), make_pair(left.first+index-1, right.second), target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        return find_matrix(matrix, make_pair(0, 0), make_pair(matrix.size()-1, matrix[0].size()-1), target);
    }
};