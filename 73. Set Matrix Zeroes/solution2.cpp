//将第一行第一列用标记处理是否需要变0
//将第一行和第一列作为标记使用

class Solution {
    bool label_i = false, label_j = false;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                //如果ij为0 则将对应的表头置0
                if (matrix[i][j] == 0){
                    //标记第一行第一列是否需要置0
                    if (i == 0){
                        label_i = true;
                    }
                    if (j == 0){
                        label_j = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //利用表头信息更新表格信息
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //将表头置0
        if (label_i){
            for (int jj = 0; jj < matrix[0].size(); jj++){
                matrix[0][jj] = 0;
            }
        }
        if (label_j){
            for (int ii = 0; ii < matrix.size(); ii++){
                matrix[ii][0] = 0;
            }
        }
    }
};
