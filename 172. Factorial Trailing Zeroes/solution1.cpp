// 寻找2和5的个数
// 方法超时

class Solution {
    long long count2 = 0, count5 = 0;
    void check_num(int n){
        while (n % 5 == 0){
            count5++;
            n = n / 5;
        }
        while (n % 2 == 0){
            count2++;
            n = n / 2;
        }
    }
public:
    int trailingZeroes(int n) {
        for (int i = 1; i <= n; i++){
            check_num(i);
        }
        return min(count2, count5);
    }
};