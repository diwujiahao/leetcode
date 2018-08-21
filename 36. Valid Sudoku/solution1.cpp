class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9], col[9], box[9];
        // 遍历九个盒子
        for (int box_num = 0; box_num < 9; box_num++){
            // 遍历盒子行数
            for (int i = 0; i < 3; i++){
                // 遍历盒子列数
                for (int j = 0; j < 3; j++){
                    // 计算行列数
                    int temp_i = box_num/3*3+i, temp_j = box_num%3*3+j;
                    if (board[temp_i][temp_j] == '.')
                        continue;
                    if (!row[temp_i].insert(board[temp_i][temp_j]).second || !col[temp_j].insert(board[temp_i][temp_j]).second || !box[box_num].insert(board[temp_i][temp_j]).second)
                        return false;
                }
            }
        }
        return true;
    }
};