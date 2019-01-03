//动态规划

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 2 || n < 2){
            return 1;
        }
        //动态规划矩阵
        //元素(i,j)表示到达当前位置的路径数量
        vector<vector<int>> path(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            path[i][0] = 1;
        }
        for (int i = 0; i < m; i++){
            path[0][i] = 1;
        }
        
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[n-1][m-1];
    }
};
