// state         incoming       next
// ones    twos    A[i]    ones    twos
// 0        0       1       1       0
// 1        0       1       0       1
// 0        1       1       0       0


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = -1;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & twos;
            twos = (twos ^ nums[i]) | ones;
        }
        return ones;
    }
};