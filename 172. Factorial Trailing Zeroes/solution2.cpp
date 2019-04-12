// 只需要统计5的个数


class Solution {
    int count5 = 0;
public:
    int trailingZeroes(int n) {
        for (long long i = 5; n / i > 0; i *= 5){
            count5 += n / i;
        }
        return count5;
    }
};




class Solution {
public:
    int trailingZeroes(int n) {
        int count5 = 0;
        while (n){
            n /= 5;
            count5 += n;
        }
        return count5;
    }
};