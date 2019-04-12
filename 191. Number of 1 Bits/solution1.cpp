class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++){
            result += n >> i & 1;
        }
        return result;
    }
};