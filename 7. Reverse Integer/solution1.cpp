class Solution {
public:
    int reverse(int x) {
    	//使用更大范围数字进行存储
        long long result = 0;
        //翻转x存入result
        while(x != 0){
            result = result * 10 + x % 10;
            x /= 10;
        }
        //判断溢出并返回
        return (result < INT_MIN || result > INT_MAX)? 0 : int(result);
    }
};