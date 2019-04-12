class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (n == m){
            return m;
        }
        // 转换为子问题
        // 当前最低位只要出现0，则结果为0
        return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
    }
};