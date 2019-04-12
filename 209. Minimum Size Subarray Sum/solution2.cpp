class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = -1;
        int sum = 0;
        
        int result = INT_MAX;
        
        while (sum >= s || right < int(nums.size())-1){
            // 当前大小还不足
            if (sum < s){
                sum += nums[++right];
            }
            // 当前大小达到要求
            else{
                result = min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};