class Solution {
    // result[i] 表示第i个解
    // result[i][j] 表示第i个解的第j行的皇后列
    vector<vector<int>> result;
    
    // 检查斜项是否有皇后冲突
    // temp的下一行，第i列放皇后
    bool check(vector<int> temp, int i, int n){
        int col_l = i - 1, col_r = i + 1;
        for (int row = int(temp.size() - 1); row >= 0; row--){
            if (col_l >= 0 && temp[row] == col_l--){
                return false;
            }
            if (col_r < n && temp[row] == col_r++){
                return false;
            }
        }
        return true;
    }
    
    // 回溯
    // temp：当前局面
    // label：使用标记
    void recursion(vector<int> temp, vector<bool> label, int n){
        if (temp.size() == label.size()){
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < label.size(); i++){
            if (!label[i] && check(temp, i, n)){
                temp.push_back(i);
                label[i] = true;
                recursion(temp, label, n);
                temp.pop_back();
                label[i] = false;
            }
        }
    }
    
    // 转换结果的格式
    vector<vector<string>> convert(vector<vector<int>> result){
        vector<vector<string>> result_s;
        for (vector<int> solution : result){
            vector<string> solution_s;
            for (int line : solution){
                string line_s(solution.size(), '.');
                line_s[line] = 'Q';
                solution_s.push_back(line_s);
            }
            result_s.push_back(solution_s);
        }
        return result_s;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        recursion(vector<int>(), vector<bool>(n, false), n);
        return convert(result);
    }
};