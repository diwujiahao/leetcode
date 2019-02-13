// 动态规划
// 节点triangle[i][j] 表示从当前节点开始走到叶子节点的最小路径和
// triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j]

class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for (int i = triangle.size() - 2; i >= 0 ; i--){
            for (int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        
        return triangle[0][0];
    }
};