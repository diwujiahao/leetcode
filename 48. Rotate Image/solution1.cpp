class Solution {
    int l = 0;
public:
    void rotate(vector<vector<int>>& matrix) {
        l = int(matrix.size());
        //遍历行
        for (int i = 0; i < l/2+l%2; i++){
            //遍历列
            for (int j = 0; j < l/2; j++){
                vector<int> temp(4);
                int row = i, col = j;
                //存储四个数
                for (int index = 0; index < 4; index++){
                    temp[index] = matrix[row][col];
                    int row_ = row;
                    row = col;
                    col = l - 1 - row_;
                }
                //重写四个数
                for (int index = 0; index < 4; index++){
                    matrix[row][col] = temp[(index+3)%4];
                    int row_ = row;
                    row = col;
                    col = l - 1 - row_;
                }
            }
        }
        
    }
};