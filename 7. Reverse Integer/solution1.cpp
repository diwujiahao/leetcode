class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x != 0){
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result < INT_MIN || result > INT_MAX)? 0 : int(result);
    }
};