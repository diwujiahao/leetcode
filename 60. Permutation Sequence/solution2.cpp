class Solution {
    string stand_string = ""; //标准顺序字符串
    string result; //结果存储
    //阶乘函数
    int factorial(int n){
        if (n == 0){
            return 0;
        }
        int r = 1;
        for (int i = 1; i <= n; i++){
            r *= i;
        }
        return r;
    }
    
public:
    string getPermutation(int n, int k) {
        // 生成标准顺序字符串
        for (int i = 1; i <= n; i++){
            stand_string += char(i + '0');
        }
        // 生成结果
        for (int i = 1; i <= n; i++){
            if (k < 2){
                result += stand_string;
                break;
            }
            int index = (k-1) / factorial(n-i);
            result += stand_string[index];
            stand_string.erase(index, 1);
            k = (k-1) % factorial(n-i) + 1;
        }
        return result;
    }
};
