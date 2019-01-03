//将待变0的非0值打标记
//第二个循环将标记变0

class Solution {
    int label = -1000000;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    for (int p = 0; p < matrix.size(); p++){
                        if (matrix[p][j] != 0){
                            matrix[p][j] = label;
                        }
                    }
                    for (int p = 0; p < matrix[0].size(); p++){
                        if (matrix[i][p] != 0){
                            matrix[i][p] = label;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == label){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};