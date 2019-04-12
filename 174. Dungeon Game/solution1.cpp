class Solution {
    vector<vector<int>> need;
    // need[i][j]表示从[i][j]开始，到达最后所需的初始血量
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = int(dungeon.size()), n = int(dungeon[0].size());
        // 初始化
        need = vector<vector<int>>(m, vector<int>(n, 0));
        need[m-1][n-1] = max(1, -1 * dungeon[m-1][n-1] + 1);
        // 初始化最后一行
        for (int j = n-2; j >= 0; j--){
            need[m-1][j] = max(1, need[m-1][j+1] - dungeon[m-1][j]);
        }
        // 初始化最后一列
        for (int i = m - 2; i >= 0; i--){
            need[i][n-1] = max(1, need[i+1][n-1] - dungeon[i][n-1]);
        }
        // 动态规划
        for (int i = m - 2; i >= 0; i--){
            for (int j = n-2; j >= 0; j--){
                int temp_need = min(need[i+1][j], need[i][j+1]) - dungeon[i][j];
                need[i][j] = max(1, temp_need);
            }
        }
        return need[0][0];
    }
};