class Solution {
    
    bool check(vector<vector<char>> &board, int i, int j, char c){
        // 第j列判断
        for (int index = 0; index < 9; index++)
            if (board[index][j] == c)   return false;
        // 第i行判断
        for (int index = 0; index < 9; index++)
            if (board[i][index] == c)   return false;
        // 方块判断
        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[row+x][col+y] == c)   return false;
        return true;
    }
    
    bool recursion(vector<vector<char>> &board, int i, int j){
        // 直接递归的情况判断
        if (i >= 9)
            return true;
        if (j >= 9)
            return recursion(board, i+1, 0);
        if (board[i][j] != '.')
            return recursion(board, i, j+1);
        // 如果当前位置为‘.’ 需要进行处理
        for (char c = '1'; c <= '9'; c++){
            // 检查当前位置填入c是否冲突
            if (check(board, i, j, c)){
                board[i][j] = c;
                if (recursion(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        recursion(board, 0, 0);
    }
};
