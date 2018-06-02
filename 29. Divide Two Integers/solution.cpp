// 基本思想: log(a/b) = log(a) - log(b)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特殊情况判断
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        // 符号变量 结果大于0为true 结果小于0为false
        bool label = !((dividend > 0) ^ (divisor > 0));
        if (divisor == 1)
            return dividend;
        long long int num1 = abs(double(dividend));
        long long int num2 = abs(double(divisor));
        double temp = log(num1) - log(num2);
        int result = pow(exp(1), temp);
        return (label) ? result : 0 - result;
    }
};