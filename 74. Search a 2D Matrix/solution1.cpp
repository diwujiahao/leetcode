class Solution {
    //二分搜索
    //输入list和target
    //返回向下取整的index
    int b_search(vector<int> list, int target){
        int left = 0, right = int(list.size()) - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (list[mid] < target){
                left = mid + 1;
            }
            else if (list[mid] > target){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        return left - 1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //特殊情况判断
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        //二分查找目标行
        vector<int> temp;
        for (int i = 0; i < matrix.size(); i++){
            temp.push_back(matrix[i][0]);
        }
        int index = b_search(temp, target);
        if (index < 0){
            return false;
        }
        //对目标行二分查找目标
        int result = b_search(matrix[index], target);
        return matrix[index][result] == target ? true : false ;
    }
};