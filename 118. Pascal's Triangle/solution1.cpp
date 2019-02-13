class Solution {
    
    vector<vector<int>> result;
    
public:
    vector<vector<int>> generate(int numRows) {
        // 搭框架
        for (int i = 0; i < numRows; i++){
            result.push_back(vector<int>(i+1));
            result[i][0] = 1;
            result[i][i] = 1;
        }
        // 填充内容
        for (int i = 2; i < numRows; i++){
            for (int index = 1; index < i; index++){
                result[i][index] = result[i-1][index-1] + result[i-1][index]; 
            }
        }
        // 返回结果
        return result;
    }
};