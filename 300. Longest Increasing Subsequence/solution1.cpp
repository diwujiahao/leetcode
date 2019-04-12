// 时间复杂度 O（n2）
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = min(1, int(nums.size()));
        for (int i = 0; i < nums.size(); i++){
            for (int j = i-1; j >= 0; j--){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    result = max(result, dp[i]);
                }
            }
        }
        return result;
    }
};