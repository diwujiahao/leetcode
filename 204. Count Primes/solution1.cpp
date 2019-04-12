class Solution {
public:
    int countPrimes(int n) {
        vector<bool> data(max(n, 2), true);
        data[0] = false;
        data[1] = false;
        
        
        for (int i = 0; i <= sqrt(n); i++){
            // 只需要检查质数的倍数就可以了，非质数一定有质数约数
            if (data[i]){
                // i的倍数全部都不是质数
                for (int k = i*i; k <= n; k += i){
                    data[k] = false;
                }
            }
        }
        
        return count(data.begin(), data.end(), true);
    }
};