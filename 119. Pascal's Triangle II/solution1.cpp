class Solution {
    
    vector<vector<int>> result;
    
public:
    vector<int> getRow(int rowIndex) {
        for (int i = 0; i <= rowIndex; i++){
            result.push_back(vector<int>(i+1));
            result[i][0] = 1;
            result[i][i] = 1;
        }
        
        for (int i = 2; i <= rowIndex; i++){
            for (int index = 1; index < i; index++){
                result[i][index] = result[i-1][index-1] + result[i-1][index]; 
            }
        }
        return result.back();
    }
};