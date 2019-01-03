class Solution {
    vector<vector<int>> result;//结果存储变量
    vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};//方向字典
    int direction_index = 0;//方向索引
    //检查是否需要转向
    bool check_next(int i, int j, int N){
        i += direction[direction_index][0];
        j += direction[direction_index][1];
        if (i >= 0 && i <= N - 1 && j >= 0 && j <= N - 1){
            if (result[i][j] == -1){
                return false;//不需要转向
            }
        }
        return true;//需要转向
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        //全局变量初始化
        result = vector<vector<int>>(n, vector<int>(n, -1));
        //填充结果变量result
        int i = 0, j = 0;
        for (int num = 1; num <= n*n; num++){
            //赋值
            result[i][j] = num;
            if (check_next(i, j, n)){
                //转向
                direction_index = (direction_index + 1) % 4;
            }
            //更新索引
            i += direction[direction_index][0];
            j += direction[direction_index][1];
        }
        
        return result;
        
    }
};