//回溯法

class Solution {
    bool check(vector<vector<char>> board, int i, int j, string temp){
        if (i < 0 || i >= board.size() || j < 0 || j > board[0].size()){
            return false;
        }
        if (board[i][j] == '0'){
            return false;
        }
        if (board[i][j] != temp[0]){
            return false;
        }
        else {
            board[i][j] = '0';
            temp.erase(temp.begin());
            if (temp.size() == 0){
                return true;
            }
            if (check(board, i-1, j, temp)){
                return true;
            }
            if (check(board, i+1, j, temp)){
                return true;
            }
            if (check(board, i, j-1, temp)){
                return true;
            }
            if (check(board, i, j+1, temp)){
                return true;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (check(board, i, j, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
