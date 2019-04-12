class Solution {
    
    // 借用了：84. Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> heights) {
        heights.push_back(0);
        stack<int> data;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++){
            while (!data.empty() && heights[i] < heights[data.top()]){
                int top = data.top();
                data.pop();
                int next_top = (data.empty()) ? -1 : data.top();
                result = max(result, (i - next_top - 1) * heights[top]);
            }
            data.push(i);
        }
        return result;
    }
    
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        vector<vector<int>> data(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        // 列处理
        for (int j = 0; j < matrix[0].size(); j++){
            data[0][j] = matrix[0][j] - '0';
            for (int i = 1; i < matrix.size(); i++){
                if (matrix[i][j] == '1'){
                    data[i][j] = data[i-1][j] + 1;
                }

            }
        }
        // 行处理
        for (int i = 0; i < matrix.size(); i++){
            result = max(result, largestRectangleArea(data[i]));
        }
        return result;
    }
};



// [1,0,1,0,0]
// [1,0,1,1,1]
// [1,1,1,1,1]
// [1,0,0,1,0]
//      |
//      |
// [1,0,1,0,0]
// [2,0,2,1,1]
// [3,1,3,2,2]
// [4,0,0,3,0]