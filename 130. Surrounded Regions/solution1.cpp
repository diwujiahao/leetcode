// 可以连接到边界的O不是封闭O
// 其余O都是封闭的

class Solution {
    void recursion(int i, int j, vector<vector<char>>& board){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return;
        }
        if (board[i][j] == 'X'){
            return;
        }
        if (board[i][j] == 'O'){
            board[i][j] = '1';
            recursion(i+1, j, board);
            recursion(i-1, j, board);
            recursion(i, j+1, board);
            recursion(i, j-1, board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0){
            return;
        }
        for (int i = 0; i < board.size(); i++){
            recursion(i, 0, board);
            recursion(i, int(board[0].size())-1, board);
        }
        for (int j = 0; j < board[0].size(); j++){
            recursion(0, j, board);
            recursion(int(board.size())-1, j, board);
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == '1'){
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else{}
            }
        }
    }
};