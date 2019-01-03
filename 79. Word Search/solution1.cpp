//回溯法

class Solution {
    bool check(vector<vector<char>> board, int i, int j, string temp){
        //当前（i，j）位置的字母匹配失败
        if (board[i][j] != temp[0]){
            return false;
        }
        //当前（i，j）位置的字母匹配成功
        else {
            // 更新board和temp
            board[i][j] = '0';
            temp.erase(temp.begin());
            // 判断是否完成匹配
            if (temp.size() == 0){
                return true;
            }
            // 遍历四个方向
            if (i - 1  >= 0 && board[i-1][j] != '0'){
                if (check(board, i-1, j, temp)){
                    return true;
                }
            }
            if (i + 1 < board.size() && board[i+1][j] != '0'){
                if (check(board, i+1, j, temp)){
                    return true;
                }
            }
            if (j - 1  >= 0 && board[i][j-1] != '0'){
                if (check(board, i, j-1, temp)){
                    return true;
                }
            }
            if (j + 1 < board[0].size() && board[i][j+1] != '0'){
                if (check(board, i, j+1, temp)){
                    return true;
                }
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
