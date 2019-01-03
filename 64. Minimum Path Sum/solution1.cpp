class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1)
            return 0;
        //获取矩阵尺寸
        int m = int(grid.size()), n = int(grid[0].size());
        //动态规划存储空间
        //元素(i,j)表示到达当前位置的最小和
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        //第一行
        for (int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        //第一列
        for (int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        //其他元素
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};