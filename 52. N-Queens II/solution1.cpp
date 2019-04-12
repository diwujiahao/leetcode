class Solution {
    int result = 0;
    
    // check_c：列使用标记
    // check_l：左斜对角使用标记
    // check_r：右斜对角使用标记
    vector<bool> check_l, check_r;
    vector<bool> check_c;
    
    // 回溯
    // temp：当前局面
    void recursion(vector<string> temp, int row, int n){
        if (row == n){
            result++;
            return;
        }
        // 回溯
        for (int i = 0; i < n; i++){
            if (!check_c[i] && !check_l[i - row + n - 1] && !check_r[row + i]){
                
                temp[row][i] = 'Q';
                check_c[i] = true;
                check_r[row + i] = true;
                check_l[i - row + n - 1] = true;
                
                recursion(temp, row + 1, n);
                
                temp[row][i] = '.';
                check_c[i] = false;
                check_r[row + i] = false;
                check_l[i - row + n - 1] = false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        check_l = vector<bool>(2*n, false);
        check_r = vector<bool>(2*n, false);
        check_c = vector<bool>(n, false);
        recursion(vector<string>(n, string(n, '.')), 0, n);
        return result;
    }
};