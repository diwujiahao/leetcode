// 回溯法
// 时间复杂度高


class Solution {
    
    vector<vector<int>> triangle_copy;
    int depth = 0;
    int result = INT_MAX;
    
    void recursion(int i, int j, int sum){
        // 超过深度--返回
        if (i == depth){
            return;
        }
        // 添加本节点
        sum += triangle_copy[i][j];
        // 判断是否符合要求
        if (i == depth - 1){
            result = min(sum, result);
        }
        // 继续回溯
        recursion(i+1, j, sum);
        recursion(i+1, j+1, sum);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        triangle_copy = triangle;
        depth = triangle.size();
        recursion(0, 0, 0);
        return result;
    }
};