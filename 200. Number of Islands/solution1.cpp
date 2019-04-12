class Solution {
    void change(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if (grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        change(grid, i+1, j);
        change(grid, i-1, j);
        change(grid, i, j+1);
        change(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    result++;
                    change(grid, i, j);
                }
            }
        }
        return result;
    }
};