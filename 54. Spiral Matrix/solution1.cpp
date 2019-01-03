class Solution {
    vector<int> result; //结果存储变量
    vector<vector<int>> label_matrix; //是否路过标记地图
    vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}}; //方向变换
    int label = 1; //路过标记
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //特殊情况判断
        if (matrix.size() == 0){
            return result;
        }
        //初始化
        label_matrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int i = 0, j = 0;
        int direction_index = 0;
        while(i > -1 && i < matrix.size() && j > -1 && j < matrix[0].size() && label_matrix[i][j] != label){
            result.push_back(matrix[i][j]);
            label_matrix[i][j] = label;
            //判断是否换方向
            int temp_i = i + direction[direction_index][0];
            int temp_j = j + direction[direction_index][1];
            if (temp_i <= -1 || temp_i >= matrix.size() || temp_j <= -1 || temp_j >= matrix[0].size() || label_matrix[temp_i][temp_j] == label){
                direction_index = (direction_index + 1) % 4;
            }
            //前进一个
            i = i + direction[direction_index][0];
            j = j + direction[direction_index][1];
        }
        return result;
    }
};