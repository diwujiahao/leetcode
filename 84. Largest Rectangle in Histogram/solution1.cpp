// 空间复杂度过高

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<vector<int>> data(heights.size(), vector<int>(heights.size(), 0));
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++){
            data[i][i] = heights[i];
            result = max(result, data[i][i]);
        }
        for (int i = 0; i < heights.size(); i++){
            for (int j = i + 1; j < heights.size(); j++){
                data[i][j] = min(data[i][j-1], heights[j]);
            }
        }
        
        for (int i = 0; i < heights.size(); i++){
            for (int j = i + 1; j < heights.size(); j++){
                data[i][j] *= j - i + 1; 
                result = max(result, data[i][j]);
            }
        }
        return result;
    }
};