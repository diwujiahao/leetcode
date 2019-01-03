class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = int(obstacleGrid.size()), n = int(obstacleGrid[0].size());
        //动态规划矩阵
        //元素(i,j)表示到达当前位置的路径数量
        vector<vector<int>> path(m, vector<int>(n, 0));
        //计算路径数
        //遇到无法通行的位置 路径数记为0
        path[0][0] = 1 * (1 - obstacleGrid[0][0]);
        for (int i = 1; i < m; i++){
            path[i][0] = path[i-1][0] * (1 - obstacleGrid[i][0]);
        }
        for (int i = 1; i < n; i++){
            path[0][i] = path[0][i-1] * (1 - obstacleGrid[0][i]);
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                path[i][j] = (path[i-1][j] + path[i][j-1]) * (1 - obstacleGrid[i][j]);
            }
        }
        return path[m-1][n-1];
    }
};
