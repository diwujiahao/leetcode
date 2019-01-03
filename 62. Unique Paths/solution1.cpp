//回溯（时间复杂度过高）

class Solution {
    int result = 0;
    
    void recursion(int pos_m, int pos_n, int m, int n){
        //到达终点
        if (pos_m == m && pos_n == n){
            result++;
            return;
        }
        //未到达终点
        //m达到极限
        if (pos_m == m){
            recursion(pos_m, pos_n+1, m, n);
        }
        //n到达极限
        else if (pos_n == n){
            recursion(pos_m+1, pos_n, m, n);
        }
        else{
            recursion(pos_m+1, pos_n, m, n);
            recursion(pos_m, pos_n+1, m, n);
        }
    }
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1){
            return 0;
        }
        recursion(1, 1, m, n);
        return result;
    }
};